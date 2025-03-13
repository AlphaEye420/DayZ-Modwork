using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

class Program
{
    static void Main()
    {
        string appVersion = "1.0";
        string dayzVersion = "DayZ 1.27";
        string expansionVersion = "Expansion 1.9.20";
        string directoryPath = AppDomain.CurrentDomain.BaseDirectory;
        string traderzonesPath = directoryPath + "\\Traderzones";
        string thresholdFilePath = directoryPath + "USER\\thresholds.json";
        string chancesFilePath = directoryPath + "USER\\chances.json";
        string settingsFilePath = directoryPath + "USER\\settings.json";
        string logFilePath = directoryPath + "USER\\Restock.log";
        string debugFilePath = directoryPath + "USER\\Debug.log";
        string logEntry = $"{DateTime.Now}: ";
        string debugEntry = $"{DateTime.Now}: ";
        Dictionary<string, int>? thresholds = null;
        Dictionary<string, int>? chances = null;
        Random rnd = new Random();
        int ConsoleLogging = 1;
        int FileLogging = 2;
        int Rando = 0;
        int itemsProcessed = 0;
        int shortCount = 0;
        int restockCount = 0;
        int fileCount = 0;
        int matchCount = 0;
        int i_itemsProcessed = 0;
        int i_shortCount = 0;
        int i_restockCount = 0;

        // Get settings
        if (File.Exists(settingsFilePath))
        {
            try
            {
                Dictionary<string, int>? logs = JsonConvert.DeserializeObject<Dictionary<string, int>>(File.ReadAllText(settingsFilePath));
                // Set
                foreach (var item in logs)
                {
                    string mName = item.Key;
                    int mValue = item.Value;
                    if (mName == "Console_Logging")
                    {
                        ConsoleLogging = mValue;
                    }
                    if (mName == "Restock_File_Logging")
                    {
                        FileLogging = mValue;
                    }
                    if (mName == "Restock_Random_Amount")
                    {
                        Rando = mValue;
                    }
                }

            }
            catch (Exception ex)
            {
                string message = $"[ERROR] Failed to load settings.json, it may be corrupt: {ex.Message}\nDefaults will be used!\n";
                Console.WriteLine(message);
                logEntry += message;
                debugEntry += message;
                ConsoleLogging = 1;
                FileLogging = 2;
                Rando = 0;
            }
        }
        else
        // Use default settings (init values)
        {
            Console.WriteLine("\n\tSETTINGS FILE MISSING - Default settings will be used\n\n");
            logEntry += $"\n\n\tSETTINGS FILE MISSING - Default settings will be used\n\n";
            debugEntry += $"\n\n\tSETTINGS FILE MISSING - Default settings will be used\n\n";
        }

        // CONSOLE START
        Console.WriteLine("DAYZ EXPANSION MARKET TRADERZONES RESTOCK APP STARTED");
        Thread.Sleep(1000);
        Console.WriteLine($"\n\tVersion: {appVersion}  |  {dayzVersion}  |  {expansionVersion} >>\n\n");
        Thread.Sleep(1000);
        Console.WriteLine("\n\tALWAYS BACK UP SERVER FILES BEFORE USING 3rd PARTY APPs !");
        Thread.Sleep(1000);
        if (ConsoleLogging > 0)
        {
            Thread.Sleep(1000);
            Console.WriteLine("\tSet inventory thresholds & chances to restock in USER folder");
            Thread.Sleep(1000);
            Console.WriteLine("\tKeep up-to-date copies of inventory files in Traderzones folder");
            Thread.Sleep(1000);
        }
        if (ConsoleLogging < 0)
        {
            Thread.Sleep(1000);
            Console.WriteLine("\tDEBUG MODE");
            Thread.Sleep(1000);
            Console.WriteLine("\tSEE USERS FOLDER DEBUG.LOG");
            Thread.Sleep(1000);
        }
        Console.WriteLine("\tCheck all files after use before synchronizing them to your server!");
        Thread.Sleep(1000);
        Console.WriteLine("\n\nWorking .... .... ....\n");

        // Continues only if passed the tests below

        // Ensure the Traderzones folder exists
        if (!Directory.Exists(traderzonesPath))
        {
            Console.WriteLine($"Error: Traderzones folder '{traderzonesPath}' not found!");
            logEntry += $" !! Error: Traderzones folder '{traderzonesPath}' not found!";
            debugEntry += $" !! Error: Traderzones folder '{traderzonesPath}' not found!";
            if (FileLogging > 0) { File.AppendAllText(logFilePath, logEntry + Environment.NewLine); }
            if (ConsoleLogging < 0) { File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine); }
            Console.WriteLine("\nExiting in 5 Seconds .. .. ..");
            Thread.Sleep(5000);
            return;
        }

        // Inventory Reset Mode:
        if (ConsoleLogging == -1 && FileLogging == -1 && Rando == -1)
        {
            Console.WriteLine("  INVENTORY RESET MODE !");
            Thread.Sleep(2000);
            Console.WriteLine("\n==================================================");
            Console.WriteLine("  ARE YOU SURE YOU WISH TO DELETE THE INVENTORY FROM");
            Console.WriteLine("  ALL Traderzones FILES?");
            Console.WriteLine("\n\tWhen you sync them to your server, upon the next restart, it will ");
            Console.WriteLine("\trepopulate them to initial values you set in your market system.");
            Console.WriteLine("\n\t  This is a good way to start over, or most people do this");
            Console.WriteLine("\t  at the time of a server wipe or traders errantly not prompting.");

            Console.WriteLine("\n==================================================\n");
            Thread.Sleep(3000);
            Console.WriteLine("  CONTINUE?");
            Console.WriteLine("\n  Press 'Y' for YES");
            Console.WriteLine("  Press 'N' (or close the console) for NO\n");

            ConsoleKeyInfo keyInfo = Console.ReadKey(true);
            if (keyInfo.Key == ConsoleKey.Y)
            {
                ResetTraderzones(directoryPath, traderzonesPath, debugFilePath);
                return; // Skip the rest of Main
            }
            else
            {
                Console.WriteLine("\nOperation canceled by user.");
                Thread.Sleep(3000);
                return; // Exit the program without doing anything
            }
        }

        // Ensure the threshold file exists AND there are no duplicates
        if (!File.Exists(thresholdFilePath))
        {
            Console.WriteLine($"Error: Threshold file '{thresholdFilePath}' not found!");
            logEntry += $" !! Error: Threshold file '{thresholdFilePath}' not found!";
            debugEntry += $" !! Error: Threshold file '{thresholdFilePath}' not found!";
            if (FileLogging > 0) { File.AppendAllText(logFilePath, logEntry + Environment.NewLine); }
            if (ConsoleLogging < 0) { File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine); }
            Console.WriteLine("\nExiting in 5 Seconds .. .. ..");
            Thread.Sleep(5000);
            return;
        }
        else if (HasDuplicateKeys(thresholdFilePath, out string duplicateThresholdKey))
        {
            Console.WriteLine($"Error: Duplicate key '{duplicateThresholdKey}' found in thresholds file!");
            logEntry += $" !! Error: Duplicate key '{duplicateThresholdKey}' found in thresholds file!";
            debugEntry += $" !! Error: Duplicate key '{duplicateThresholdKey}' found in thresholds file!";
            if (FileLogging > 0) { File.AppendAllText(logFilePath, logEntry + Environment.NewLine); }
            if (ConsoleLogging < 0) { File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine); }
            Console.WriteLine("\nExiting in 5 Seconds .. .. ..");
            Thread.Sleep(5000);
            return;
        }

        // Ensure the chances file exists AND there are no duplicates
        if (!File.Exists(chancesFilePath))
        {
            Console.WriteLine($"Error: Chances file '{chancesFilePath}' not found!");
            logEntry += $" !! Error: Chances file '{chancesFilePath}' not found!";
            debugEntry += $" !! Error: Chances file '{chancesFilePath}' not found!";
            if (FileLogging > 0) { File.AppendAllText(logFilePath, logEntry + Environment.NewLine); }
            if (ConsoleLogging < 0) { File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine); }
            Console.WriteLine("\nExiting in 5 Seconds .. .. ..");
            Thread.Sleep(5000);
            return;
        }
        else if (HasDuplicateKeys(chancesFilePath, out string duplicateChancesKey))
        {
            Console.WriteLine($"Error: Duplicate key '{duplicateChancesKey}' found in chances file!");
            logEntry += $" !! Error: Duplicate key '{duplicateChancesKey}' found in chances file!";
            debugEntry += $" !! Error: Duplicate key '{duplicateChancesKey}' found in chances file!";
            if (FileLogging > 0) { File.AppendAllText(logFilePath, logEntry + Environment.NewLine); }
            if (ConsoleLogging < 0) { File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine); }
            Console.WriteLine("\nExiting in 5 Seconds .. .. ..");
            Thread.Sleep(5000);
            return;
        }

        try
        {
            thresholds = JsonConvert.DeserializeObject<Dictionary<string, int>>(File.ReadAllText(thresholdFilePath));
        }
        catch (Exception ex)
        {
            string message = $"\n\n[FATAL ERROR] Failed to load thresholds.json, it may be corrupt: {ex.Message}\n\n\t Exiting Program!";
            Console.WriteLine(message);
            logEntry += message;
            debugEntry += message;
            if (FileLogging > 0) { File.AppendAllText(logFilePath, logEntry + Environment.NewLine); }
            if (ConsoleLogging < 0) { File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine); }
            Thread.Sleep(5000);
            return;
        }
        // Continues only if passed the above tests
        // Below can continue on if errors
        try
        {
            chances = JsonConvert.DeserializeObject<Dictionary<string, int>>(File.ReadAllText(chancesFilePath));
        }
        catch (Exception ex)
        {
            string message = $"[ERROR] Failed to load chances.json, it may be corrupt: {ex.Message}\nRestocked values will equal thresholds\n";
            Console.WriteLine(message);
            logEntry += message;
            debugEntry += message;
        }
        var jsonFiles = Directory.GetFiles(traderzonesPath, "*.json");

        // Start Searching Each File
        foreach (string filePath in jsonFiles)
        {
            bool fileUpdated = false;
            bool printed = false;
            string jsonText = File.ReadAllText(filePath);
            JObject json = JObject.Parse(jsonText);
            fileCount += 1;
            i_itemsProcessed = 0;
            i_shortCount = 0;
            i_restockCount = 0;

            // Check if Item exists
            if (json.ContainsKey("Stock") && json["Stock"] is JObject stock)
            {
                if (FileLogging > 2) { logEntry += $"\n\t'{Path.GetFileNameWithoutExtension(filePath)}': "; }
                if (ConsoleLogging < 0) { debugEntry += $"\nFILE: {Path.GetFileNameWithoutExtension(filePath)} "; }
                if (ConsoleLogging > 0) { Console.WriteLine($"Updating {Path.GetFileName(filePath)}: "); }

                // Update Item ?
                foreach (var item in thresholds)
                {
                    string itemName = item.Key;
                    int minValue = item.Value;
                    int diceRoll = rnd.Next(1, 101);
                    bool passRoll = !chances.ContainsKey(itemName) || chances[itemName] >= diceRoll;
                    itemsProcessed += 1;
                    i_itemsProcessed += 1;
                    if (stock.ContainsKey(itemName)) { matchCount += 1; }

                    // Update each item that passes thresholds and dice roll
                    if (stock.ContainsKey(itemName) && passRoll == true)
                    {
                        if (ConsoleLogging < 0) { debugEntry += $"\n\tITEM: {itemName} "; }
                        if (ConsoleLogging < 0) { debugEntry += $" : Chance Roll: {chances[itemName]} BEAT {diceRoll}"; }
                        shortCount += 1;
                        i_shortCount += 1;
                        int currentValue = stock[itemName]!.Value<int>();
                        if (currentValue < minValue)
                        {
                            // Figure random amount to stock
                            if (Rando > 0)
                            {
                                int randoRoll = rnd.Next(1, 101);
                                int e = (int)Math.Round((minValue - currentValue) * (0.01 * randoRoll));
                                stock[itemName] = currentValue + Math.Max(1, e);
                                if (ConsoleLogging < 0) { debugEntry += $" : Restock Chance Roll: {stock[itemName]} of {minValue} possible"; }
                            }
                            else
                            // Stock to threshold amount
                            {
                                stock[itemName] = minValue;
                                if (ConsoleLogging < 0) { debugEntry += $" : ReStock To Threshold: {stock[itemName]}"; }
                            }

                            // Log the update
                            //if (FileLogging > 2 && printed == false) { logEntry += "\n\t\t"; }
                            if (FileLogging == 2 && printed == false) { logEntry += $"\n\t'{Path.GetFileNameWithoutExtension(filePath)}': "; }
                            if (FileLogging == 1 && printed == false) { logEntry += $"'{Path.GetFileNameWithoutExtension(filePath)}': "; }
                            fileUpdated = true;
                            printed = true;
                            restockCount += 1;
                            i_restockCount += 1;
                            logEntry += $"{itemName}<{currentValue}>{stock[itemName]}, ";
                            if (ConsoleLogging > 0) { Console.WriteLine($"\t{itemName} {currentValue} to {stock[itemName]}, "); }
                            if (ConsoleLogging < 0) { debugEntry += $"\n\t\tRestocked {currentValue} to {stock[itemName]}"; }
                        }
                    }

                    // Handle each item that passes thresholds and FAILED dice roll
                    if (stock.ContainsKey(itemName) && passRoll == false)
                    {
                        int currentValue = stock[itemName]!.Value<int>();

                        // Logging
                        if (currentValue < minValue)
                        {
                            shortCount += 1;
                            i_shortCount += 1;
                        }
                        if (FileLogging > 2 && currentValue > 0 && currentValue < minValue)
                        {
                            //if (printed == false) { logEntry += "\n\t\t"; }
                            logEntry += $"{itemName}<LOW>, ";
                            printed = true;
                        }
                        else if (FileLogging > 2 && currentValue < minValue)
                        {
                            //if (printed == false) { logEntry += "\n\t\t"; }
                            logEntry += $"{itemName}<OUT>, ";
                            printed = true;
                        }

                        // Debug
                        if (ConsoleLogging < 0) { debugEntry += $"\n\tITEM: {itemName} "; }
                        if (ConsoleLogging < 0)
                        {
                            debugEntry += $": {currentValue} In Stock";
                        }
                        if (ConsoleLogging < 0 && currentValue > 0 && currentValue < minValue)
                        {
                            debugEntry += $"\n\t\tChanceRoll: {chances[itemName]} MISSED {diceRoll}; Remains LOW on Stock";
                        }
                        else if (ConsoleLogging < 0 && currentValue < minValue)
                        {
                            debugEntry += $"\n\t\tChanceRoll: {chances[itemName]} MISSED {diceRoll}; Remains OUT of Stock";
                        }
                    }
                }
                if (FileLogging > 2) { logEntry += $"\n\t  {i_itemsProcessed} items processed: {i_restockCount} of a possible {i_shortCount} Items Restocked at {Path.GetFileNameWithoutExtension(filePath)}"; }
                if (ConsoleLogging < 0) { debugEntry += $"\n\t  {i_itemsProcessed} items processed: {i_restockCount} of a possible {i_shortCount} Items Restocked at {Path.GetFileNameWithoutExtension(filePath)}"; }
            }

            // Save the updated JSON only if changes were made
            if (fileUpdated)
            {
                File.WriteAllText(filePath, JsonConvert.SerializeObject(json, Formatting.Indented));
                if (ConsoleLogging > 0) { Console.WriteLine($"{Path.GetFileName(filePath)} Saved !\n"); }
                if (ConsoleLogging < 0) { debugEntry += $"\n  JSON Saved !"; }
            }
            else
            {
                if (ConsoleLogging > 0) { Console.WriteLine("\t No Changes Made to the json;"); }
                if (ConsoleLogging < 0) { debugEntry += $"\n  No Changes Made to the json;"; }
            }
        }

        // Finalize and Print Logs
        if (FileLogging > 0)
        {
            logEntry += $"\n  {itemsProcessed} checks of {thresholds.Count} json items: {matchCount} matches found in {fileCount} Traderzones, {restockCount} of a possible {shortCount} Items Restocked\n_____";
            File.AppendAllText(logFilePath, logEntry + Environment.NewLine);
        }
        if (ConsoleLogging < 0)
        {
            debugEntry += $"\n\n  {itemsProcessed} checks of {thresholds.Count} json items: {matchCount} matches found in {fileCount} Traderzones, {restockCount} of a possible {shortCount} Items Restocked\n_____ Done.";
            File.AppendAllText(debugFilePath, debugEntry + Environment.NewLine);
        }

        // CONSOLE END
        Thread.Sleep(500);
        Console.WriteLine("\n.. .. .. Done!");
        Console.WriteLine($"\n< {itemsProcessed} checks of {thresholds.Count} json Items >\n< Matched {matchCount} items in {fileCount} Traderzones >\n< {restockCount} of a possible {shortCount} Items Restocked >");
        Thread.Sleep(500);
        Console.WriteLine("\n==================================================");
        Console.WriteLine("   Process Complete. See 'USER\\Restock.log' for details.");
        Console.WriteLine("==================================================\n");
        Thread.Sleep(500);
        Console.WriteLine("Press any key to exit... (Auto-closing in 30 seconds)");

        Task waitForKey = Task.Run(() => Console.ReadKey(true));
        bool keyPressed = Task.WaitAny(new[] { waitForKey }, TimeSpan.FromSeconds(30)) == 0;

        if (keyPressed)
        {
            Console.WriteLine("Key pressed. Exiting...");
        }
        else
        {
            Console.WriteLine("Timeout reached. Auto-closing...");
        }

    }

    // Helper function to check for duplicate keys in a JSON file
    static bool HasDuplicateKeys(string filePath, out string duplicateKey)
    {
        var keySet = new HashSet<string>();
        duplicateKey = null;

        using (var sr = new StreamReader(filePath))
        using (var reader = new JsonTextReader(sr))
        {
            string currentProperty = null;

            while (reader.Read())
            {
                if (reader.TokenType == JsonToken.PropertyName)
                {
                    currentProperty = reader.Value.ToString();

                    if (!keySet.Add(currentProperty))
                    {
                        duplicateKey = currentProperty;
                        return true; // Duplicate found                        
                    }
                }
            }
        }

        return false; // No duplicates
    }

    static void ResetTraderzones(string directoryPath, string traderzonesPath, string debugFilePath)
    {
        Console.WriteLine("\n=== RESETTING ALL TRADERZONES ===\n");

        string backupPath;
        string[] jsonFiles;
        try
        {
            backupPath = Path.Combine(directoryPath, "Backup_" + DateTime.Now.ToString("yyyyMMdd_HHmmss"));
            Directory.CreateDirectory(backupPath);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"[ERROR] Could not create backup folder: {ex.Message}");
            File.AppendAllText(debugFilePath, $"[ERROR] Could not create backup folder: {ex.Message}\n");
            return;
        }

        try
        {
            jsonFiles = Directory.GetFiles(traderzonesPath, "*.json");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"[ERROR] Could not find Traderzones folder: {ex.Message}");
            File.AppendAllText(debugFilePath, $"[ERROR] Could not find Traderzones folder: {ex.Message}\n");
            return;
        }

        foreach (var file in jsonFiles)
        {
            try
            {
                // BACKUP before wiping
                string backupFile = Path.Combine(backupPath, Path.GetFileName(file));
                File.Copy(file, backupFile, true);

                // Now clear the stock
                string jsonText = File.ReadAllText(file);
                JObject json = JObject.Parse(jsonText);

                if (json.ContainsKey("Stock"))
                {
                    json["Stock"] = new JObject(); // Clears the stock list
                    File.WriteAllText(file, JsonConvert.SerializeObject(json, Formatting.Indented));

                    Console.WriteLine($"Cleared Stock in {Path.GetFileName(file)}");

                    // Log to debug file
                    string debugEntry = $"{DateTime.Now}: Cleared Stock in {Path.GetFileName(file)} (Backup created: {backupFile}){Environment.NewLine}";
                    File.AppendAllText(debugFilePath, debugEntry);
                }
            }
            catch (Exception ex)
            {
                string error = $"{DateTime.Now}: Error clearing stock in {Path.GetFileName(file)} - {ex.Message}{Environment.NewLine}";
                Console.WriteLine(error);
                File.AppendAllText(debugFilePath, error);
            }
        }

        Console.WriteLine("\n=== RESET COMPLETE ===\n");
        Console.WriteLine($"  A backup of the Traderzones files has been created at:\n  {backupPath}\n");

        Console.WriteLine("Press any key to exit... (Auto-closing in 30 seconds)");
        Task waitForKey = Task.Run(() => Console.ReadKey(true));
        bool keyPressed = Task.WaitAny(new[] { waitForKey }, TimeSpan.FromSeconds(30)) == 0;

        if (keyPressed)
        {
            Console.WriteLine("Key pressed. Exiting...");
        }
        else
        {
            Console.WriteLine("Timeout reached. Auto-closing...");
        }
    }
}
