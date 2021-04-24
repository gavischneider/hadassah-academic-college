package com.hadassah.ex2_schneider;

import com.google.gson.Gson;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

@WebServlet(name = "AnswersServlet", value = "/AnswersServlet")
public class AnswersServlet extends HttpServlet {

    ArrayList<Answer> answers = new ArrayList<Answer>();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        PrintWriter toClient = response.getWriter();

        // Extract question id from request
        int question = Integer.parseInt(request.getParameter("question"));

        // Find all the answers for the question
        ArrayList<Answer> currentAnswers = new ArrayList<Answer>();
        for (Answer answer: answers) {
            if (answer.getQuestion() == question) {
                currentAnswers.add(answer);
            }
        }

        // Create JSON object from answers
        Gson g = new Gson();
        String json = g.toJson(currentAnswers);

        // Return JSON to client
        toClient.print(json);
        toClient.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        // Extract parameters from request
        int question = Integer.parseInt(request.getParameter("question"));
        String text = request.getParameter("text");
        String user = request.getParameter("user");

        // Create new answer object and store it
        Answer answer = new Answer(question, text, user);
        answers.add(answer);

        System.out.println("Answers DS: ");
        System.out.println(answers);
    }
}
