package com.hadassah.ex3_schneider;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Session {
    String url;
    ExecutorService executor;
    int imageCount;

    public Session() {
        this.url = "";
        this.executor = Executors.newFixedThreadPool(2);
        this.imageCount = 0;
    }
}
