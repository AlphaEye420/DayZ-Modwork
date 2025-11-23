param([string[]]$files)

if ($files.Count -eq 0) {
    Write-Host "No input files."
    exit
}

$all = New-Object System.Collections.Generic.HashSet[string]

foreach ($file in $files) {

    if (-not (Test-Path $file)) { continue }

    try {
        $json = Get-Content $file -Raw | ConvertFrom-Json
    } catch {
        Write-Host "Skipping unreadable file: $file"
        continue
    }

    if ($null -eq $json.Items) { continue }

    foreach ($item in $json.Items) {

        # Base ClassName
        if ($item.ClassName) {
            $all.Add($item.ClassName) | Out-Null
        }

        # Variants[]
        if ($item.Variants) {
            foreach ($v in $item.Variants) {
                if ($v -and $v.Trim() -ne "") {
                    $all.Add($v.Trim()) | Out-Null
                }
            }
        }
    }
}

# Sort results alphabetically
$sorted = $all | Sort-Object

# Write .txt file
$outFile = "ClassList.txt"
Set-Content -Path $outFile -Value $sorted -Encoding UTF8

Write-Host "Created $outFile with $($sorted.Count) classnames."
