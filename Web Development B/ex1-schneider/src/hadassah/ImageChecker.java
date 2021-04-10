package hadassah;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import java.io.IOException;

public class ImageChecker implements Checker{

    char command = 0;
    String url = null;

    public ImageChecker(char theCommand, String theUrl) {
        this.command = theCommand;
        this.url = theUrl;
    }

    @Override
    public boolean check() {

        try {
            // Check for img tags
            Document doc = Jsoup.connect(url).get();
            Element imageElement = doc.select("img").first();
            return imageElement != null;
        }
        catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }
}
