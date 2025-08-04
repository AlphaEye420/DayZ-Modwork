param (
    [string]$XmlPath
)

if (-not (Test-Path $XmlPath)) {
    Write-Host "❌ File not found: $XmlPath"
    exit 1
}

try {
    [xml]$xml = Get-Content -LiteralPath $XmlPath -ErrorAction Stop
} catch {
    Write-Host "❌ Failed to read XML: $_"
    exit 1
}

$counts = @{}

foreach ($node in $xml.SelectNodes("//group")) {
    $name = $node.GetAttribute("name")
    if (![string]::IsNullOrWhiteSpace($name)) {
        if (-not $counts.ContainsKey($name)) {
            $counts[$name] = 0
        }
        $counts[$name]++
    }
}

# Output path
$outfile = [System.IO.Path]::Combine((Split-Path $XmlPath), "object_count.json")

# Write plain text instead of JSON
try {
	$entries = $counts.GetEnumerator() | Sort-Object Name
	$lines = @()
	$lines += "{"
	for ($i = 0; $i -lt $entries.Count; $i++) {
		$name = $entries[$i].Key
		$count = $entries[$i].Value
		$comma = if ($i -lt $entries.Count - 1) { "," } else { "" }
		$lines += "    `"$name`": $count$comma"
	}
	$lines += "}"
    Set-Content -Path $outfile -Value $lines -Encoding UTF8
    Write-Host "✅ Wrote object_count.json to: $outfile"
} catch {
    Write-Host "❌ Failed to write TXT: $_"
    exit 1
}
