package hadassah;

import java.awt.*;
import java.util.Arrays;
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

        boolean result = validateInput(command, url, argument);
        if (!result) {
            System.exit(0);
        }

        System.out.println("Command is: " + command);
        System.out.println("URL is: " + url);
        System.out.println("Argument is: " + argument);
    }

    public boolean validateInput(String command, String url, String argument) {
        String[] arr = {"a", "b", "c"};
        if (!Arrays.asList(arr).contains(command)){
            System.out.println("Invalid Command!");
            return false;
        }
        return  true;
    }
}
