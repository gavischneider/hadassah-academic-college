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
            if (file.isFile()) {
                Scanner in = new Scanner(file);
                while (in.hasNextLine()){
                    String currentLine = in.nextLine();
                    String[] splitLine = currentLine.split(" ");
                    Collections.addAll(words, splitLine);
                }

                //for (String word : words) {
                  //  System.out.println(word);
                //}


                return words;
            }
            else {
                System.out.println("File does not exist: " + path);
                throw new FileNotFoundException();
            }
        }
        catch (FileNotFoundException e) {
            words.add("fileNoGood");
            return words;
        }
    }
}

// w https://en.wikipedia.org/wiki/Main_Page src/hadassah/words.txt

//src/hadassah/words.txt

//Web Development B/ex1-schneider/src/hadassah/words.txt