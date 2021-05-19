package com.hadassah.ex3_schneider;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingDeque;

public class ThreadController {
    BlockingQueue<Integer> blockingQueue = new LinkedBlockingDeque<>(2);
    ExecutorService executor = Executors.newFixedThreadPool(2);
    String url;

    public ThreadController(String url) {
        this.url = url;
    }

    public void createNewThread() {
        // Create new thread, use it to create a new web crawler
        Thread newThread = new Thread(() -> {
            System.out.println("Starting Thread for url " + url);
            System.out.println("Begin crawling " + url + " at depth 0");
            new WebCrawler().getPageLinks(url, 0);
        });
        newThread.start();
    }
}
