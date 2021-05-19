package com.hadassah.ex3_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.time.Instant;

@WebServlet(name = "WebCrawlerServlet", value = "/WebCrawlerServlet")
public class WebCrawlerServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get url parameter from html form
        String url = request.getParameter("url");

        //ThreadController threadController = new ThreadController(url);
        //threadController.createNewThread();

        // Create new session and start web crawler
        Long id = Instant.now().toEpochMilli();
        request.getSession(true).setAttribute("id", id);
        new WebCrawler().newUrl(url, 0, id);

        // Redirect user to next page
        response.setContentType("text/html");
        RequestDispatcher view = request.getRequestDispatcher("/html/crawling.html");
        view.forward(request, response);
    }
}
