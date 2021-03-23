package hadassah;

import java.util.Scanner;

public class UrlCheckApp {

    // --------- Constructors ---------
    public UrlCheckApp(){
        initializeApp();
    }

    // --------- Methods --------------
    public void initializeApp() {
        System.out.println("Welcome to URLCheck.");
        appManager();
    }

    public void appManager() {
        while (true) {

            // 1. Get input from user
            System.out.println("Please enter a command, URL and arguments: \n");
            Scanner scanner = new Scanner(System.in);
            String input = scanner.nextLine();
            String[] separatedInput = input.split(" ");

            String command = separatedInput[0];

            // If command is 'q', exit program
            if (command.equals("q")) {
                System.exit(0);
            }

            String url = separatedInput[1];
            String argument = "";

            // Check if there's an argument
            if (separatedInput.length > 2) {
                argument = separatedInput[2];
            }

            // 2. Make sure entered input is valid
            ValidateInput validateInput = new ValidateInput(command, url, argument);
            boolean result = validateInput.checkCommand();
            if (!result) {
                System.exit(0);
            }
            boolean result2 = validateInput.checkUrl();
            if (!result2) {
                System.exit(0);
            }
            //boolean result3 = validateInput.checkArgument();
            //if (!result3) {
            //    System.exit(0);
            //}

            System.out.println("Command is: " + command);
            System.out.println("URL is: " + url);
            System.out.println("Argument is: " + argument);

            // 3. Execute command
            CommandManager commandManager = new CommandManager(command, url, argument);
            commandManager.execute();
        }
    }
}
