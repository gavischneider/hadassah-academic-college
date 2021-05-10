package com.hadassah.ex3_schneider;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.HashSet;

public class WebCrawler {
    private static final int MAX_DEPTH = 2;
    private HashSet<String> links;
    static int imageCount = 0;

    public WebCrawler() {
        links = new HashSet<>();
    }

    public void getPageLinks(String URL, int depth) {
        if ((!links.contains(URL) && (depth < MAX_DEPTH))) {
            System.out.println(">> Depth: " + depth + " [" + URL + "]");
            try {
                links.add(URL);

                // We've now added the current URL to links, lets check it for images and then check it for other URLs
                getPageImages(URL);

                // Now we'll check the URL for other URLs on the page
                Document document = Jsoup.connect(URL).get();
                Elements linksOnPage = document.select("a[href]");

                depth++;
                for (Element page : linksOnPage) {
                    getPageLinks(page.attr("abs:href"), depth);
                }
            } catch (IOException e) {
                System.err.println("For '" + URL + "': " + e.getMessage());
            }
        }
    }

    public void getPageImages(String URL) {
        try {
            Document document = Jsoup.connect(URL).get();
            Elements imagesOnPage = document.select("img");
             for (Element image : imagesOnPage) {
                 imageCount++;
                 System.out.println("Image count is now: " + imageCount);
             }
        } catch (IOException e) {
            System.err.println("Error opening URL while searching for images");
        }
    }

    public static void main(String[] args) {
        new WebCrawler().getPageLinks("http://www.mkyong.com/", 0);
    }
}
