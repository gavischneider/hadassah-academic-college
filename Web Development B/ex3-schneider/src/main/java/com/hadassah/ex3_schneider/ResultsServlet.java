package com.hadassah.ex3_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * ResultsServlet: Retrieves results data and displays it to the user
 */
@WebServlet(name = "ResultsServlet", value = "/ResultsServlet")
public class ResultsServlet extends HttpServlet {
    /**
     * \
     * @param request - Incoming request
     * @param response - Outgoing response
     * @throws ServletException - Servlet exception
     * @throws IOException - Input output exception
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get the users session
        Long id = (Long) request.getSession().getAttribute("id");

        // Check if the web crawler is still running
        Boolean finished = WebCrawler.getFinished(id);
        String finishedString;
        if(finished) {
            finishedString = String.format("<h1>Finished crawling %s </h1>", WebCrawler.getUrl(id));
        } else {
            finishedString = String.format("<h1> Crawling: %s </h1>", WebCrawler.getUrl(id)) + "Refresh page for updated results";
        }
        PrintWriter out = response.getWriter();
        out.println("<html><body>" +
                finishedString +
                String.format("<p> Found %d images </p>", WebCrawler.getImageCount(id)) +
                "<a href=index.html>Home Page</a>" +
                "</body>" +
                "</html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
