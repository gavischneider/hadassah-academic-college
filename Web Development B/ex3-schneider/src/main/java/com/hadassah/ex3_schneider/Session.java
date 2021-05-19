package com.hadassah.ex3_schneider;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Session class
 */
public class Session {
    /**
     * url - url that user provided
     * executor - service that runs the web crawler
     * imageCount - how many images the web crawler has discovered
     */
    String url;
    ExecutorService executor;
    int imageCount;

    /**
     * Session constructor
     */
    public Session() {
        this.url = "";
        this.executor = Executors.newFixedThreadPool(2);
        this.imageCount = 0;
    }
}
