package com.example.ex4;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import javax.servlet.http.HttpServletRequest;

/**
 * 'Main' controller - starts the application
 */
@SpringBootApplication
@Controller
public class Ex4Application {

    public static void main(String[] args) {
        SpringApplication.run(Ex4Application.class, args);
    }

    /**
     *
     * @param request - Incoming request object
     * @return - The index page, or redirect to /login if the user is not logged in
     */
    @GetMapping("/")
    public Object home(HttpServletRequest request){
        // Check if user is logged in or not
        String username = (String) request.getSession().getAttribute("username");
        System.out.println("-----> Username: " + username);

        // If not logged in --> login
        if (username == null){
            return "redirect:/login";
        }

        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("user", username);
        return modelAndView;
    }

    /**
     *
     * @param request - Incoming request object
     * @return - The index page
     */
    @GetMapping("/index")
    public Object index(HttpServletRequest request){
        String username = (String) request.getSession().getAttribute("username");
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("user", username);
        return modelAndView;
    }

    /**
     *
     * @param request - Incoming request object
     * @return - Boolean, whether there's a user logged in or not
     */
    @GetMapping("/session")
    @ResponseBody
    public Boolean checkSession(HttpServletRequest request){
        String username = (String) request.getSession().getAttribute("username");
        return username != null;
    }
}
