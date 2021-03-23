package hadassah;

public class CommandManager {

    private char command;
    private String url = "";
    private String argument = "";

    public CommandManager(String theCommand, String theUrl, String theArgument) {
        this.command = theCommand.charAt(0);
        this.url = theUrl;
        this.argument = theArgument;
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
