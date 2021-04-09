package hadassah;

import javax.imageio.IIOException;
import java.io.FileNotFoundException;
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
        char c = command.charAt(0);

        switch (c) {
            case 't':
                String[] tAllowedArgs = {"text", "text/html", "img", "img/gif"};
                // If command is 't', only one arg may be given
                if (args.size() != 1) {
                    return false;
                }
                // Check if arg is allowed, if not return false
                return Arrays.asList(tAllowedArgs).contains(args.get(0));
            case 'w':
                // Arg should be a path to a file of words
                if (args.size() != 1) {
                    return false;
                }
                ExtractWords extractor = new ExtractWords(args.get(0));
                ArrayList<String> words = extractor.getWordsFromFile();
                // If there are no words, return true
                if (words.size() == 0) {
                    return true;
                }
                return !words.get(0).equals("fileNoGood");
            case 'i':
                // In this case there should be no args
                return args.size() == 0;
            case 'l':
                // there must be exactly 1 arg - 'english'
                if (args.size() != 1) {
                    return false;
                }
                return args.get(0).equalsIgnoreCase("english");
            default:
                break;
        }
        return false;
    }
}
