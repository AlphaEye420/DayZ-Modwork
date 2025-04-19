using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

class Program
{    static void Main()
    {
        string appVersion = "1.1";
        string dayzVersion = "DayZ 1.27";
        string expansionVersion = "Expansion 1.9.20";
        string directoryPath = AppDomain.CurrentDomain.BaseDirectory;
        string traderzonesPath;
        string settingsFilePath = directoryPath + "USER\\traderzones_path.txt";

        try
        {
            string Content = File.ReadAllText(settingsFilePath);
            traderzonesPath = Content;
            AlphabetizeTraderzoneStocks(traderzonesPath);
        }
        catch (Exception ex)
        {
            string message = $"[ERROR] Failed to load traderzones_path.txt, it may be corrupt or missing!\n";
            Console.WriteLine(message);
            Thread.Sleep(5000);
            return;          
        }
    }
    public static void AlphabetizeTraderzoneStocks(string traderzonesFolder)
    {
        if (!Directory.Exists(traderzonesFolder))
        {
            Console.WriteLine($"Traderzones folder not found: {traderzonesFolder}");
            return;
        }

        string[] jsonFiles = Directory.GetFiles(traderzonesFolder, "*.json");

        foreach (string file in jsonFiles)
        {
            try
            {
                string jsonText = File.ReadAllText(file);

                JObject jsonObj = JObject.Parse(jsonText);

                if (!jsonObj.ContainsKey("Stock"))
                {
                    Console.WriteLine($"No 'Stock' section found in {Path.GetFileName(file)} - skipping.");
                    continue;
                }

                // Get the Stock object
                JObject stockObj = jsonObj["Stock"] as JObject;

                if (stockObj == null || stockObj.Count == 0)
                {
                    Console.WriteLine($"Empty 'Stock' in {Path.GetFileName(file)} - skipping.");
                    continue;
                }

                // Sort keys alphabetically and create a new ordered JObject
                var sortedStock = new JObject();

                foreach (var prop in stockObj.Properties().OrderBy(p => p.Name))
                {
                    sortedStock.Add(prop.Name, prop.Value);
                }

                // Replace the old Stock with the sorted one
                jsonObj["Stock"] = sortedStock;

                // Serialize back to JSON with indents
                string sortedJson = JsonConvert.SerializeObject(jsonObj, Formatting.Indented);

                // Write the sorted JSON back to the file
                File.WriteAllText(file, sortedJson);

                Console.WriteLine($"Sorted 'Stock' in {Path.GetFileName(file)}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error processing {Path.GetFileName(file)}: {ex.Message}");
                Thread.Sleep(5000);
            }
        }

        Console.WriteLine("\nAll Traderzones files have been sorted.");
        Thread.Sleep(5000);
    }
}
