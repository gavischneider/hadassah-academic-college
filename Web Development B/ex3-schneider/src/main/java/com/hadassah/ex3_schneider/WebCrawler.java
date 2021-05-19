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
        // Create a new executor service to run our task
        ExecutorService executor = getExecutor(id);

        Runnable task = () -> {
            System.out.println("Starting Thread for url: " + URL);
            getPageLinks(URL, depth, id);
            System.out.println("Number of images found for " + URL + ": " + imageCount);
            System.out.println("End crawling " + URL + " at depth " + MAX_DEPTH);
            System.out.println("End of thread for url: " + URL);
        };
        executor.execute(task);
        executor.shutdown();
    }

    public void getPageLinks(String URL, int depth, Long id) {
        sessionStorage.get(id).url = URL;
        if ((!links.contains(URL) && (depth < MAX_DEPTH))) {
            System.out.println("Begin crawling " + URL + " at depth " + depth);
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
             }
        } catch (IOException e) {
            System.err.println("Error opening URL while searching for images");
        }
    }

    // Getter functions that return session info
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

    public static Boolean getFinished(Long id) {
        ExecutorService executor = sessionStorage.get(id).executor;
        return executor.isTerminated();
    }
}
