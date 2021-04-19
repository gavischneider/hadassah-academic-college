package com.hadassah.ex2_schneider;

import java.io.*;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

//@WebServlet(name = "helloServlet", value = "/hello-servlet")
@WebServlet(urlPatterns = {"/index.html"})
public class HomeServlet extends HttpServlet {
    private String message;

    public void init() {
        message = "Hello World!";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        //response.setContentType("text/html");

        // Hello
        //PrintWriter out = response.getWriter();
        //out.println("<html><body>");
        //out.println("<h1>" + message + "</h1>");
        //out.println("</body></html>");

        // Return HTML page
        RequestDispatcher view = request.getRequestDispatcher("/html/index.html");
        view.forward(request, response);
    }

    public void destroy() {
    }
}