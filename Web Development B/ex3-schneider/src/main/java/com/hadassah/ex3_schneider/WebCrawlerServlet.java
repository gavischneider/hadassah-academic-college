package com.hadassah.ex3_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;
import java.time.Instant;


/**
 * WebCrawlerServlet
 */
@WebServlet(name = "WebCrawlerServlet", value = "/WebCrawlerServlet")
public class WebCrawlerServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }

    /**
     *
     * @param request - Incoming request
     * @param response - Outgoing response
     * @throws ServletException - Servlet exception
     * @throws IOException - Input output exception
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get url parameter from html form
        String url = request.getParameter("url");

        // URL validation
        try {
            URL urlObject = new URL(url);
            URLConnection urlConnection = urlObject.openConnection(); // Throws IOException when it can't open
            urlConnection.connect();
        } catch (IOException e) {
            e.printStackTrace();

            // Redirect user to error page
            response.setContentType("text/html");
            RequestDispatcher view = request.getRequestDispatcher("/html/error.html");
            view.forward(request, response);
        }


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
