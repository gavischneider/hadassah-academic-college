package hadassah;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ExtractWords {

    private String path = "";

    public ExtractWords(String pathToFile) {
        this.path = pathToFile;
    }

    public ArrayList<String> getWordsFromFile() {
        ArrayList<String> words = new ArrayList<String>();
        File file = new File(path);

        try {
            // Check if file exists and is not a folder
            if (file.exists() && !file.isDirectory()) {
                Scanner in = new Scanner(file);
                while (in.hasNextLine()){
                    String currentLine = in.nextLine();
                    String[] splitLine = currentLine.split(" ");
                    Collections.addAll(words, splitLine);
                }
                return words;
            }
            else {
                throw new FileNotFoundException();
            }
        }
        catch (FileNotFoundException e) {
            words.add("fileNoGood");
            return words;
        }
    }
}
