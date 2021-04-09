package hadassah;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
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
            ArrayList<String> args = new ArrayList<String>();

            // Check if there's an argument
            if (separatedInput.length > 2) {
                // Add the argument(s) to the args array
                args.addAll(Arrays.asList(separatedInput).subList(2, separatedInput.length));
            }

            // 2. Make sure entered input is valid
            ValidateInput validateInput = new ValidateInput(command, url, args);
            boolean result = validateInput.checkCommand();
            if (!result) {
                System.out.println("false");
            }
            boolean result2 = validateInput.checkUrl();
            if (!result2) {
                System.out.println("false");
            }
            boolean result3 = validateInput.checkArgument();
            if (!result3) {
                System.out.println("false");
            }

            System.out.println("Command is: " + command);
            System.out.println("URL is: " + url);
            System.out.println("Arguments are: ");
            for (String arg : args) {
                System.out.println(arg + " ");
            }

            // 3. Execute command
            CommandManager commandManager = new CommandManager(command, url, args);
            commandManager.execute();
        }
    }
}
