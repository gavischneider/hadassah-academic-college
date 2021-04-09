package hadassah;

import javax.imageio.IIOException;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Arrays;

public class ValidateInput {

    // --------- Variables ------------
    private String command = "";
    private String url = "";
    private ArrayList<String> args;
    public String[] commands = {"t", "w", "i", "l", "q"};

    // --------- Constructors ---------
    public ValidateInput(String theCommand, String theUrl, ArrayList<String> theArguments) {
        this.command = theCommand;
        this.url = theUrl;
        this.args = theArguments;
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
            URLConnection urlConnection = urlObject.openConnection(); // Throws IOException when it can't open
            urlConnection.connect(); // Throws UnknownHostException when it can't connect
        }
        catch(UnknownHostException e)
        {
            System.out.println("error");
            return false;
        }
        catch(MalformedURLException e)
        {
            System.out.println("Bad URL");
            return false;
        }
        catch(IOException e) {
            System.out.println("error");
            return false;
        }
        return true;
    }

    public boolean checkArgument() {
        return false;
    }
}
