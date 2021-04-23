package com.hadassah.ex2_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "AnswersServlet", value = "/AnswersServlet")
public class AnswersServlet extends HttpServlet {

    ArrayList<Answer> answers = new ArrayList<Answer>();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int question = Integer.parseInt(request.getParameter("question"));

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
