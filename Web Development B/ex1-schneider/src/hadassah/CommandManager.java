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

    public boolean execute() {
        switch (command) {
            case 't':
                ContentTypeChecker contentChecker = new ContentTypeChecker(command, url, args.get(0));
                return contentChecker.check();
            case 'w':
                WordChecker wordChecker = new WordChecker();
                return wordChecker.check();
            case 'i':
                ImageChecker imageChecker = new ImageChecker();
                return imageChecker.check();
            case 'l':
                LanguageChecker languageChecker = new LanguageChecker();
                return languageChecker.check();
            default:
                break;
        }
        return false;
    }
}
