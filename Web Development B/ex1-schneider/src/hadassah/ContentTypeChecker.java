package hadassah;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

public class ContentTypeChecker implements Checker{

    char command = 0;
    String url = null;
    String arg = null;

    public ContentTypeChecker(char theCommand, String theUrl, String theArgument) {
        this.command = theCommand;
        this.url = theUrl;
        this.arg = theArgument;
    }

    @Override
    public boolean check() {
        try {
            URL obj = new URL(url);
            URLConnection conn = obj.openConnection(); // Throws IOException when it can't open

            String contentTypeHeader = conn.getHeaderField("Content-Type");
            System.out.println("Content Type Header: " + contentTypeHeader);

            // Remove any extra headers
            if (contentTypeHeader.contains(";")) {
                contentTypeHeader = contentTypeHeader.split(";")[0];
            }
            // img == image
            if (contentTypeHeader.startsWith("image")) {
                contentTypeHeader = contentTypeHeader.replaceFirst("image", "img");
            }

            // Check if content type header matches the given argument
            return contentTypeHeader.startsWith(arg);
        }
        catch (MalformedURLException e) {
            e.printStackTrace();
            return false;
        }
        catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }
}
