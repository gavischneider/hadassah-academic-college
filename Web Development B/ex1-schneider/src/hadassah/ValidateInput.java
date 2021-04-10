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

    // Check if the command is allowed, throws exception otherwise
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

    // Check if the URL is good, throws exception otherwise
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

    // Check if the argument(s) are allowed, throws exception otherwise
    public boolean checkArgument() {
        try {
            char c = command.charAt(0);
            switch (c) {
                // Content Type
                case 't':
                    String[] tAllowedArgs = {"text", "text/html", "img", "img/gif"};
                    // If command is 't', only one arg may be given
                    if (args.size() != 1) {
                        throw new InvalidArgumentException();
                    }
                    // Check if arg is allowed, if not return false
                    if (!Arrays.asList(tAllowedArgs).contains(args.get(0))) {
                        throw new InvalidArgumentException();
                    } else {
                        return true;
                    }
                // Word Search
                case 'w':
                    // Arg should be a path to a file of words
                    if (args.size() != 1) {
                        throw new InvalidArgumentException();
                    }
                    ExtractWords extractor = new ExtractWords(args.get(0));
                    ArrayList<String> words = extractor.getWordsFromFile();
                    // If there are no words, return true
                    if (words.size() == 0) {
                        return true;
                    }
                    if (words.get(0).equals("fileNoGood")) {
                        throw new InvalidArgumentException();
                    }
                    return true;
                // Image Search
                case 'i':
                    // In this case there should be no args
                    if (args.size() != 0) {
                        throw new InvalidArgumentException();
                    }
                    return true;
                // Language
                case 'l':
                    // there must be exactly 1 arg - 'english'
                    if (args.size() != 1) {
                        throw new InvalidArgumentException();
                    }
                    if (!args.get(0).equalsIgnoreCase("english")) {
                        throw new InvalidArgumentException();
                    }
                    return true;
                default:
                    break;
            }
        }
        catch(InvalidArgumentException e){
            return false;
        }
        return false;
    }
}
