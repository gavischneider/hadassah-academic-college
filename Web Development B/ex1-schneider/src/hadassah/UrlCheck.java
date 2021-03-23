package hadassah;

import java.awt.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;
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

        // Check command
        String[] arr = {"t", "w", "i", "l", "q"};
        if (!Arrays.asList(arr).contains(command)){
            System.out.println("Invalid Command!"); // todo - create exception
            return false;
        }

        // Check URL
        try {
            URL urlObject = new URL(url);
            URLConnection urlConnection = urlObject.openConnection();
            urlConnection.connect(); // Throws UnknownHostException when it cant connect
            System.out.println("URL exists");
        }
        catch(UnknownHostException e)
        {
            System.out.println("URL either doesn't exist or unable to connect at this moment");
            return false;
        }
        catch(MalformedURLException e)
        {
            System.out.println("Bad URL");
            return false;
        }
        catch(Exception e) {
            e.printStackTrace();
            return false;
        }

        // Check argument
        return  true;
    }
}
