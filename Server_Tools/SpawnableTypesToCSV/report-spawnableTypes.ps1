param(
    [string]$CsvFile = "SpawnableTypes.csv",
    [string]$XmlFile = "RebuiltSpawnableTypes.xml"
)

$rows = Import-Csv -Path $CsvFile

# Create new XML doc
$xml = New-Object System.Xml.XmlDocument
$root = $xml.CreateElement("spawnabletypes")
$xml.AppendChild($root) | Out-Null

# Group rows by TypeName (blank for top-level stuff)
$grouped = $rows | Group-Object TypeName

foreach ($group in $grouped) {
    $typeName = $group.Name

    if ([string]::IsNullOrWhiteSpace($typeName)) {
        # Top-level entries (only damage is expected)
        foreach ($r in $group.Group | Where-Object { $_.Category -eq "damage" }) {
            $damageNode = $xml.CreateElement("damage")
            $damageNode.SetAttribute("min", $r.DamageMin)
            $damageNode.SetAttribute("max", $r.DamageMax)
            $root.AppendChild($damageNode) | Out-Null
        }
        continue
    }

    # Make <type name="...">
    $typeNode = $xml.CreateElement("type")
    $typeNode.SetAttribute("name", $typeName)
    $root.AppendChild($typeNode) | Out-Null

    foreach ($r in $group.Group) {
        switch ($r.Category) {
            "damage" {
                $damageNode = $xml.CreateElement("damage")
                if ($r.DamageMin) { $damageNode.SetAttribute("min", $r.DamageMin) }
                if ($r.DamageMax) { $damageNode.SetAttribute("max", $r.DamageMax) }
                $typeNode.AppendChild($damageNode) | Out-Null
            }
            default {
                if ($r.ItemName) {
                    # Parent node (cargo, attachments, etc.)
                    $parentNode = $xml.CreateElement($r.Category)
                    if ($r.Preset) { $parentNode.SetAttribute("preset", $r.Preset) }
                    if ($r.ParentChance) { $parentNode.SetAttribute("chance", $r.ParentChance) }

                    # Item node
                    $itemNode = $xml.CreateElement("item")
                    $itemNode.SetAttribute("name", $r.ItemName)
                    if ($r.ItemChance) { $itemNode.SetAttribute("chance", $r.ItemChance) }
                    $parentNode.AppendChild($itemNode) | Out-Null

                    $typeNode.AppendChild($parentNode) | Out-Null
                }
                else {
                    # Just a preset/chance node with no items
                    $parentNode = $xml.CreateElement($r.Category)
                    if ($r.Preset) { $parentNode.SetAttribute("preset", $r.Preset) }
                    if ($r.ParentChance) { $parentNode.SetAttribute("chance", $r.ParentChance) }
                    $typeNode.AppendChild($parentNode) | Out-Null
                }
            }
        }
    }
}

# Save output
$xml.Save($XmlFile)
Write-Host "XML written to $XmlFile"
