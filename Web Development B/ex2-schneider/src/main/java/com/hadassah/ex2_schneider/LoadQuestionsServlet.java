package com.hadassah.ex2_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "LoadQuestionsServlet", value = "/LoadQuestionsServlet")
public class LoadQuestionsServlet extends HttpServlet {

    String file;

    @Override
    public void init() {
        // application wide parameter stored in web.xml
        file = this.getServletContext().getInitParameter("file");

    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter toClient = response.getWriter();

        // Open file
        String path = request.getServletContext().getRealPath("/docs/" + file);
        toClient.println("Path: ");
        toClient.println(path);
        toClient.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }



}
