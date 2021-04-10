package hadassah;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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
                String pattern = "(?m)(^|\\s)" + word + "(\\s|$)";
                Pattern p = Pattern.compile(pattern);
                Matcher m = p.matcher(pageText);
                if (m.find()) {
                    wordCount++;
                }
            }

            // Check percentage
            return wordCount / commonWords.length >= 0.85;

        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }
}
