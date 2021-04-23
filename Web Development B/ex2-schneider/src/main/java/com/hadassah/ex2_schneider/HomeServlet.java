package com.hadassah.ex2_schneider;

import java.io.*;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

//@WebServlet(urlPatterns = {"/index.html"})
@WebServlet(name = "HomeServlet", value = "/index.html")
public class HomeServlet extends HttpServlet {

    public void init() {
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html");

        // Forward the request to LoadQuestionsServlet
        //RequestDispatcher rd = request.getRequestDispatcher("/LoadQuestionsServlet");
        //rd.forward(request, response);

        RequestDispatcher view = request.getRequestDispatcher("/html/index.html");
        view.forward(request, response);
    }

    public void destroy() {
    }
}