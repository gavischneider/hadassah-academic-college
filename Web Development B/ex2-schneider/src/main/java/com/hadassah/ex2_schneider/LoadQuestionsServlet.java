package com.hadassah.ex2_schneider;

import com.google.gson.Gson;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

@WebServlet(name = "LoadQuestionsServlet", value = "/LoadQuestionsServlet")
public class LoadQuestionsServlet extends HttpServlet {

    String file;
    ArrayList<Question> questions = new ArrayList<Question>();

    @Override
    public void init() {
        // Application wide parameter stored in web.xml
        file = this.getServletContext().getInitParameter("file");
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        PrintWriter toClient = response.getWriter();

        // Open file
        String path = request.getServletContext().getRealPath("/docs/" + file);
        File file = new File(path);

        try {
            // Check if file exists and is not a folder
            if (file.isFile()) {
                int i = 0;
                Scanner in = new Scanner(file);
                while (in.hasNextLine()){
                    Question tempQuestion = new Question(i, in.nextLine());
                    questions.add(tempQuestion);
                    i++;
                }

                // Create JSON object from questions
                Gson g = new Gson();
                String json = g.toJson(questions);

                // Return JSON to client
                toClient.print(json);
                toClient.close();
            }
            else {
                throw new FileNotFoundException();
            }
        }
        catch (FileNotFoundException e) {
            toClient.println("Error opening file...");
            toClient.close();
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        // Extract question from request
        int question = Integer.parseInt(request.getParameter("question"));

        // Increment answers by 1
        for (Question q : questions) {
            if (q.id == question) {
                q.answers++;
            }
        }

        RequestDispatcher view = request.getRequestDispatcher("/html/index.html");
        view.forward(request, response);
    }

}
