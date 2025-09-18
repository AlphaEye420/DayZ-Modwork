param(
    [string]$XmlFile = "cfgSpawnableTypes.xml",
    [string]$CsvFile = "SpawnableTypes.csv"
)

# Load XML
try {
    [xml]$xml = Get-Content -Path $XmlFile -ErrorAction Stop
} catch {
    Write-Host "Error: cannot read file '$XmlFile' - $($_.Exception.Message)" -ForegroundColor Red
    exit 1
}

$rows = @()

# 1) Top-level <damage> nodes (no TypeName)
foreach ($damage in $xml.DocumentElement.SelectNodes('damage')) {
    $rows += [pscustomobject]@{
        TypeName       = ''
        Category       = 'damage'
        Preset         = ''
        ParentChance   = ''
        ItemName       = ''
        ItemChance     = ''
        Chance         = ''
        EffectiveChance= ''
        DamageMin      = $damage.GetAttribute('min')
        DamageMax      = $damage.GetAttribute('max')
    }
}

# 2) All <type> nodes
foreach ($type in $xml.DocumentElement.SelectNodes('type')) {
    $typeName = $type.GetAttribute('name')

    # 2a) Any <damage> nodes inside this <type>
    foreach ($d in $type.SelectNodes('damage')) {
        $rows += [pscustomobject]@{
            TypeName       = $typeName
            Category       = 'damage'
            Preset         = ''
            ParentChance   = ''
            ItemName       = ''
            ItemChance     = ''
            Chance         = ''
            EffectiveChance= ''
            DamageMin      = $d.GetAttribute('min')
            DamageMax      = $d.GetAttribute('max')
        }
    }

    # 2b) All descendant <item> nodes (captures attachments/cargo/... items anywhere under the type)
    foreach ($item in $type.SelectNodes('.//item')) {
        $parent = $item.ParentNode
        $category = $parent.Name
        $preset = $parent.GetAttribute('preset')
        $parentChance = $parent.GetAttribute('chance')
        $itemName = $item.GetAttribute('name')
        $itemChance = $item.GetAttribute('chance')

        # prefer itemChance, otherwise parentChance
        $chanceToUse = if ($itemChance -and $itemChance.Trim() -ne '') { $itemChance } elseif ($parentChance -and $parentChance.Trim() -ne '') { $parentChance } else { '' }

        # compute effective chance if both parent & item are numeric
        $effective = ''
        if ($parentChance -and $itemChance) {
            try {
                $p = [double]::Parse($parentChance, [System.Globalization.CultureInfo]::InvariantCulture)
                $i = [double]::Parse($itemChance,   [System.Globalization.CultureInfo]::InvariantCulture)
                $effective = ($p * $i).ToString([System.Globalization.CultureInfo]::InvariantCulture)
            } catch {
                $effective = ''
            }
        }

        $rows += [pscustomobject]@{
            TypeName        = $typeName
            Category        = $category
            Preset          = $preset
            ParentChance    = $parentChance
            ItemName        = $itemName
            ItemChance      = $itemChance
            Chance          = $chanceToUse
            EffectiveChance = $effective
            DamageMin       = ''
            DamageMax       = ''
        }
    }

    # 2c) Direct child element nodes that do NOT contain <item> descendants
    #      e.g. <cargo preset="mixArmy" /> or <attachments preset="bagsArmy" /> with no <item>
    $childElements = @($type.ChildNodes | Where-Object { $_.NodeType -eq [System.Xml.XmlNodeType]::Element })
    foreach ($child in $childElements) {
        if ($child.Name -eq 'damage') { continue }   # already handled above
        if ($child.SelectNodes('.//item').Count -gt 0) { continue } # already handled by 2b

        $preset = $child.GetAttribute('preset')
        $chance = $child.GetAttribute('chance')

        # Add a row describing this preset/chance (no specific item)
        if ($preset -or $chance) {
            $rows += [pscustomobject]@{
                TypeName        = $typeName
                Category        = $child.Name
                Preset          = $preset
                ParentChance    = $chance
                ItemName        = ''
                ItemChance      = ''
                Chance          = $chance
                EffectiveChance = ''
                DamageMin       = ''
                DamageMax       = ''
            }
        }
    }
}

# Export CSV with stable column order
$rows |
    Select-Object TypeName,Category,Preset,ParentChance,ItemName,ItemChance,Chance,EffectiveChance,DamageMin,DamageMax |
    Export-Csv -Path $CsvFile -NoTypeInformation -Encoding UTF8 -Force

Write-Host "CSV written to '$CsvFile' (`$rows.Count rows)" -ForegroundColor Green
