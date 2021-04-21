package com.hadassah.ex2_schneider;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

@WebServlet(name = "LoadQuestionsServlet", value = "/LoadQuestionsServlet")
public class LoadQuestionsServlet extends HttpServlet {

    String file;
    ArrayList<String> questions = new ArrayList<String>();

    @Override
    public void init() {
        // Application wide parameter stored in web.xml
        file = this.getServletContext().getInitParameter("file");

    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter toClient = response.getWriter();

        // Open file
        String path = request.getServletContext().getRealPath("/docs/" + file);
        File file = new File(path);

        try {
            // Check if file exists and is not a folder
            if (file.isFile()) {
                Scanner in = new Scanner(file);
                while (in.hasNextLine()){
                    Collections.addAll(questions, in.nextLine());
                }
                toClient.println("Questions: ");
                toClient.println(questions);
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

    }



}
