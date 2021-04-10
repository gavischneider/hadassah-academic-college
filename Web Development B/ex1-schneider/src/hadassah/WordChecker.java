package hadassah;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Locale;

public class WordChecker implements Checker{

    char command = 0;
    String url = null;
    String arg = null;

    public WordChecker(char theCommand, String theUrl, String theArgument) {
        this.command = theCommand;
        this.url = theUrl;
        this.arg = theArgument;
    }

    @Override
    public boolean check() {
        try {
            ExtractWords extractor = new ExtractWords(arg);
            ArrayList<String> words = extractor.getWordsFromFile();

            // If there are no words, return true
            if (words.size() == 0) {
                return true;
            }
            // Check that all the given words exist on the page
            Document doc = Jsoup.connect(url).get();
            String pageText = doc.body().text();

            for (String word: words) {
                if (!pageText.toLowerCase().contains(word.toLowerCase())) {
                    return false;
                }
            }
            return true;
        }
        catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }
}
