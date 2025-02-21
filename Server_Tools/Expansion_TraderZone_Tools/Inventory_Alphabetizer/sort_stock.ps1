param (
    [string]$inputFile
)

# Read the JSON file as a string
$jsonContent = Get-Content -Raw -Path $inputFile

# Convert to a PowerShell object
$json = $jsonContent | ConvertFrom-Json

# Check if "Stock" exists and is an object (hashtable)
if ($json.PSObject.Properties.Name -contains "Stock") {
    # Create a new ordered hashtable
    $sortedStock = [ordered]@{}

    # Sort Stock keys alphabetically and add them to the ordered hashtable
    foreach ($key in ($json.Stock.PSObject.Properties.Name | Sort-Object)) {
        $sortedStock[$key] = $json.Stock.$key
    }

    # Assign the sorted stock back
    $json.Stock = $sortedStock
}

# Convert back to JSON (with indentation)
$formattedJson = $json | ConvertTo-Json -Depth 10

# Fix indentation: replace 14 spaces with 4 spaces
$formattedJson = $formattedJson -replace ' {14}', '    '

# Fix indentation: replace : 2 spaces with : 1 space
$formattedJson = $formattedJson -replace ':  ', ': '

# Save the modified JSON back to the file
$formattedJson | Set-Content -Path $inputFile -Encoding UTF8

Write-Host "Sorted Stock section and fixed indentation in $inputFile"
