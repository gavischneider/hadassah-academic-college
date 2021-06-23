package com.example.ex4.controllers;

import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;

@Controller
public class LoginController {
    @Autowired
    private UserRepository userRepository;
    private UserRepository getRepo() {
        return userRepository;
    }

    @GetMapping("/login")
    public Object loginPage(Model model, HttpServletRequest request) {
        String username = (String) request.getSession().getAttribute("username");
        if(username != null) {
            return "redirect:/index";
        }

        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("login");
        return modelAndView;
    }

    @PostMapping("/login")
    public Object login(@RequestParam String username, Model model, HttpServletRequest request){
        User user = getRepo().findByUsername(username);
        if(user == null){
            // Username is available, add name to session
            request.getSession().setAttribute("username", username);

            // Add user to database
            User newUser = new User(username);
            getRepo().save(newUser);
            return "redirect:/index";
        } else {
            System.out.println("user found: " + user);
            // Username is taken
            ModelAndView modelAndView = new ModelAndView();
            modelAndView.setViewName("login_error");
            return modelAndView;
        }
    }

    @PostMapping("/logout")
    public void logout(Model model, HttpServletRequest request) {
        User user = getRepo().findByUsername((String) request.getSession().getAttribute("username"));
        request.getSession().invalidate();
        getRepo().delete(user);
    }
}
