package hadassah;

import java.util.ArrayList;

public class CommandManager {

    private char command;
    private String url = "";
    private ArrayList<String> args;

    public CommandManager(String theCommand, String theUrl, ArrayList<String> theArguments) {
        this.command = theCommand.charAt(0);
        this.url = theUrl;
        this.args = theArguments;
    }

    public void execute() {
        switch (command) {
            case 't':
                //code
                break;
            case 'w':
                // code
                break;
            case 'i':
                // code
                break;
            case 'l':
                // code
                break;
            default:
                break;
        }
    }
}
