package com.hadassah.ex2_schneider;

import java.io.*;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

/**
 * Home servlet - sends the user to the index page
 */
@WebServlet(name = "HomeServlet", value = "/index.html")
public class HomeServlet extends HttpServlet {

    /**
     * Init method
     */
    public void init() {
    }

    /**
     *
     * @param request Incoming request
     * @param response Outgoing response
     * @throws IOException Input output exception
     * @throws ServletException Servlet exception
     */
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html");
        RequestDispatcher view = request.getRequestDispatcher("/html/index.html");
        view.forward(request, response);
    }

    /**
     * Destroy method
     */
    public void destroy() {
    }
}