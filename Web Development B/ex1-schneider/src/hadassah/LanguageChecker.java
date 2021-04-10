package hadassah;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

import java.io.IOException;

public class LanguageChecker implements Checker{

    char command = 0;
    String url = null;
    String arg = null;

    public LanguageChecker(char theCommand, String theUrl, String theArgument) {
        this.command = theCommand;
        this.url = theUrl;
        this.arg = theArgument;
    }

    @Override
    public boolean check() {
        try {
            // Check how many common English words appear on the page
            String[] commonWords = {"to", "the", "is", "it", "of", "and", "a", "in", "you", "that", "he", "she", "was", "for", "on", "are", "as", "with", "I", "his", "they"};
            float wordCount = 0;
            Document doc = Jsoup.connect(url).get();
            String pageText = doc.body().text();

            for (String word: commonWords) {
                if (pageText.toLowerCase().contains(word.toLowerCase())) {
                    wordCount++;
                }
            }

            // Check percentage
            return wordCount / commonWords.length >= 0.8;

        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }
}
