package com.hadassah.ex3_schneider;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.concurrent.ExecutorService;

public class WebCrawler {
    private static final int MAX_DEPTH = 2;
    private static final HashMap<Long, Session> sessionStorage = new HashMap<>();
    private HashSet<String> links = new HashSet<>();
    static int imageCount = 0;

    public WebCrawler() { }

    public void newUrl(String URL, int depth, Long id) {
        ExecutorService executor = getExecutor(id);

        Runnable producerTask = () -> {
            System.out.println("Starting thread for url: " + URL);
            getPageLinks(URL, depth, id);
            //this.done = true;

            System.out.println("End of thread for url: " + URL);
        };
        executor.execute(producerTask);

        executor.shutdown();
    }

    public void getPageLinks(String URL, int depth, Long id) {
        sessionStorage.get(id).url = URL;
        if ((!links.contains(URL) && (depth < MAX_DEPTH))) {
            System.out.println(">> Depth: " + depth + " [" + URL + "]");
            try {
                links.add(URL);

                // We've now added the current URL to links, lets check it for images and then check it for other URLs
                getPageImages(URL, id);

                // Now we'll check the URL for other URLs on the page
                Document document = Jsoup.connect(URL).get();
                Elements linksOnPage = document.select("a[href]");

                depth++;
                for (Element page : linksOnPage) {
                    getPageLinks(page.attr("abs:href"), depth, id);
                }
            } catch (IOException e) {
                System.err.println("For '" + URL + "': " + e.getMessage());
            }
        }
    }

    public void getPageImages(String URL, Long id) {
        try {
            Document document = Jsoup.connect(URL).get();
            Elements imagesOnPage = document.select("img");
             for (Element image : imagesOnPage) {
                 imageCount++;
                 sessionStorage.get(id).imageCount = imageCount;
                 System.out.println("Image count is now: " + imageCount);
                 //System.out.println("Crawling URL " + URL + " Current results: " + imageCount + " images found");
             }
        } catch (IOException e) {
            System.err.println("Error opening URL while searching for images");
        }
    }

    public static String getUrl(Long id) {
        return sessionStorage.get(id).url;
    }

    private static ExecutorService getExecutor(Long id){
        if(!sessionStorage.containsKey(id))
        {
            Session session = new Session();
            sessionStorage.put(id, session);
        }
        return sessionStorage.get(id).executor;
    }

    public static int getImageCount(Long id) {
        return sessionStorage.get(id).imageCount;
    }
}
