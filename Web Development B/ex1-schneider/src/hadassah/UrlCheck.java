package hadassah;

import java.util.Scanner;

public class UrlCheck {

    // --------- Constructors ---------
    public UrlCheck(){
        initializeApp();
    }

    // --------- Methods --------------
    public void initializeApp(){
        System.out.println("Initialized!!");

        System.out.println("Welcome to URLCheck. Please enter a command, URL and arguments: \n");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] separatedInput = input.split(" ");

        String command = separatedInput[0];
        String url = separatedInput[1];
        String argument = separatedInput[2];

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
    }
}
