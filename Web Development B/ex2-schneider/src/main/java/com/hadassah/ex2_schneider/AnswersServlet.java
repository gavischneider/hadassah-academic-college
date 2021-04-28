package com.hadassah.ex2_schneider;

import com.google.gson.Gson;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 * Answers servlet:
 * Returns all the answers for a specific question in JSON
 * Adds a new answer to the answers list
 */
@WebServlet(name = "AnswersServlet", value = "/AnswersServlet")
public class AnswersServlet extends HttpServlet {

    /**
     * List of answers
     */
    ArrayList<Answer> answers = new ArrayList<Answer>();

    /**
     *
     * @param request Incoming request
     * @param response Outgoing response
     * @throws ServletException Servlet exception
     * @throws IOException Input output exception
     */
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

    /**
     *
     * @param request Incoming request
     * @param response Outgoing response
     * @throws ServletException Servlet exception
     * @throws IOException Input output exception
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        try {
            // Extract parameters from request
            int question = Integer.parseInt(request.getParameter("question"));
            String text = request.getParameter("text").trim();
            String user = request.getParameter("user").trim();

            // Validate Parameters
            if (question < 0) {
                throw new IllegalParameterException();
            }
            if (text.isEmpty()) {
                throw new IllegalParameterException();
            }
            if (user.isEmpty()) {
                throw new IllegalParameterException();
            }

            // Create new answer object and store it
            Answer answer = new Answer(question, text, user);
            answers.add(answer);

            // Forward the request to LoadQuestionsServlet
            RequestDispatcher rd = request.getRequestDispatcher("/LoadQuestionsServlet");
            rd.forward(request, response);
        }
        catch(IllegalParameterException e) {
            RequestDispatcher view = request.getRequestDispatcher("/html/invalidParameter.html");
            view.forward(request, response);
        }
    }
}
