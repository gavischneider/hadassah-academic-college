package com.hadassah.ex3_schneider;

import java.io.*;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "HomeServlet", value = "/index.html")
public class HomeServlet extends HttpServlet {

    public void init() {}

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html");
        RequestDispatcher view = request.getRequestDispatcher("/html/index.html");
        view.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        // Get url parameter from html form
        String url = request.getParameter("url");

        // Create new thread, use it to create a new web crawler
        Thread newThread = new Thread(() -> {
            System.out.println("Starting Thread for url " + url);
            new WebCrawler().getPageLinks(url, 0);
            System.out.println("Begin crawling " + url + " at depth 0");
        });
        newThread.start();

        try {
            newThread.join();
            System.out.println("THREAD HAS ENDED!!!!!");

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Redirect user to next page
        response.setContentType("text/html");
        RequestDispatcher view = request.getRequestDispatcher("/html/crawling.html");
        view.forward(request, response);
    }

    public void destroy() {
    }
}