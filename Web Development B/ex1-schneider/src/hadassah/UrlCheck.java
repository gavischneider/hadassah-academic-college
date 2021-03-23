package hadassah;

import java.util.Scanner;

public class UrlCheck {

    public UrlCheck(){
        initializeApp();
    }

    public void initializeApp(){
        System.out.println("Initialized!!");

        System.out.println("Welcome to URLCheck. Please enter a command, URL and arguments: \n");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] separatedInput = input.split(" ");

        String command = separatedInput[0];
        String url = separatedInput[1];
        String argument = separatedInput[2];
        // Check input

        System.out.println("Command is: " + command);
        System.out.println("URL is: " + url);
        System.out.println("Argument is: " + argument);
    }
}
