package hadassah;

import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;
import java.util.Arrays;

public class ValidateInput {

    // --------- Variables ------------
    private String command;
    private String url;
    private String argument;
    public String[] commands = {"t", "w", "i", "l", "q"};

    // --------- Constructors ---------
    public ValidateInput(String theCommand, String theUrl, String theArgument) {
        this.command = theCommand;
        this.url = theUrl;
        this.argument = theArgument;
    }

    // --------- Methods --------------
    public boolean checkCommand() {
        try {
            if (!Arrays.asList(commands).contains(command)) {
                System.out.println("Invalid command");
                throw new InvalidCommandException();
            }
        }
        catch(InvalidCommandException e) {
            return false;
        }
        catch(Exception e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public boolean checkUrl() {
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
        return true;
    }

    public boolean checkArgument() {
        return false;
    }
}
