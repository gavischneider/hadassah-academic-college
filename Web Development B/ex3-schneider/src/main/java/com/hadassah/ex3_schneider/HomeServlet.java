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
        // Todo:
        // 1. Get url parameter from html form
        // 2. Create new thread
        // 3. Start thread with url --> call the web crawler
        // 4. Redirect user to next page

        String url = request.getParameter("url");

        Thread newThread = new Thread() {
            public void run() {
                new WebCrawler().getPageLinks(url, 0);
            }
        };
        newThread.start();

        response.setContentType("text/html");
        RequestDispatcher view = request.getRequestDispatcher("/html/crawling.html");
        view.forward(request, response);
    }

    public void destroy() {
    }
}