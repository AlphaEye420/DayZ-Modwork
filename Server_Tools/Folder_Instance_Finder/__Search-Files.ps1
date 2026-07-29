# Search-Files.ps1
# Interactive search tool for *.json, *.xml, and *.map files

while ($true) {
    # Prompt for input
    $FolderPath = Read-Host "Enter folder path to search (or just Enter to quit)"
    if ([string]::IsNullOrWhiteSpace($FolderPath)) { break }

    $SearchText = Read-Host "Enter text to search for (or just Enter to quit)"
    if ([string]::IsNullOrWhiteSpace($SearchText)) { break }

    Write-Host "`nSearching in: $FolderPath"
    Write-Host "Looking for: $SearchText`n"

    # Check folder exists
    if (-not (Test-Path $FolderPath)) {
        Write-Host "Error: Folder not found!" -ForegroundColor Red
        continue
    }

    # Perform the search
    $results = Get-ChildItem -Path $FolderPath -Recurse -Include *.json, *.xml, *.map -ErrorAction SilentlyContinue |
        Select-String -Pattern $SearchText -SimpleMatch

    foreach ($r in $results) {
        Write-Output "$($r.Path):$($r.LineNumber)  $($r.Line)"
    }

    # Summary
    Write-Host "`nSearch complete."
    if ($results.Count -gt 0) {
        Write-Host "Found $($results.Count) result(s)." -ForegroundColor Green
    } else {
        Write-Host "No matches found." -ForegroundColor Yellow
    }

    Write-Host "`n--- Start a new search ---`n"
}
