package com.example.ex4;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;

@SpringBootApplication
@Controller
public class Ex4Application {

    public static void main(String[] args) {
        SpringApplication.run(Ex4Application.class, args);

    }

    @GetMapping("/")
    public Object home(Model model, HttpServletRequest request){
        // Check if user is logged in or not
        String username = (String) request.getSession().getAttribute("username");
        System.out.println("-----> Username: " + username);

        // If not logged in --> login
        if (username == null){
            return "redirect:/login";
        }

        // If logged in --> index
        //return "redirect:/index";

        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("user", username);
        return modelAndView;
    }

    @GetMapping("/index")
    public Object index(Model model, HttpServletRequest request){
        String username = (String) request.getSession().getAttribute("username");
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("user", username);
        return modelAndView;
    }

    @GetMapping("/session")
    @ResponseBody
    public Boolean checkSession(Model model, HttpServletRequest request){
        String username = (String) request.getSession().getAttribute("username");
        return username != null;
    }
}
