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

/**
 * Questions servlet:
 * loads the questions from the file
 * Increments questions answer count when a new answer is added
 */
@WebServlet(name = "LoadQuestionsServlet", value = "/LoadQuestionsServlet")
public class LoadQuestionsServlet extends HttpServlet {

    /**
     * Questions file
     */
    String file;
    /**
     * List of questions
     */
    ArrayList<Question> questions = new ArrayList<Question>();

    /**
     * Init method - gets the questions file
     */
    @Override
    public void init() {
        // Application wide parameter stored in web.xml
        file = this.getServletContext().getInitParameter("file");
    }

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

    /**
     *
     * @param request Incoming request
     * @param response Outgoing response
     * @throws ServletException Servlet exception
     * @throws IOException Input output exception
     */
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
