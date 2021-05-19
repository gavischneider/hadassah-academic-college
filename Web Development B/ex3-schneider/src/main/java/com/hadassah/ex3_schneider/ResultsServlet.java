package com.hadassah.ex3_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ResultsServlet", value = "/ResultsServlet")
public class ResultsServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Get the users session
        Long id = (Long) request.getSession().getAttribute("id");

        PrintWriter out = response.getWriter();
        out.println("<html><body>" +
                String.format("<h1> Crawling: %s </h1>", WebCrawler.getUrl(id)) +
                String.format("<p> found %d images </p>", WebCrawler.getImageCount(id)) +
                "<a href=\"/home\">Home Page</a>" +
                "</body>" +
                "</html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
