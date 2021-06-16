package com.example.ex4.controllers;

import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class LoginController {
    @Autowired
    private UserRepository userRepository;

    private UserRepository getRepo() {
        return userRepository;
    }

    @GetMapping("/login")
    public ModelAndView loginPage() {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("login");
        return modelAndView;
    }

    @PostMapping("/login")
    public ModelAndView login(@RequestParam String username){
        User user = getRepo().findByUsername(username);
        if(user == null){
            System.out.println("**");
            System.out.println(user);
            // Username is available
            User newUser = new User(username);
            getRepo().save(newUser);
            ModelAndView modelAndView = new ModelAndView();
            modelAndView.setViewName("index");
            modelAndView.addObject("user", username);
            return modelAndView;
        } else {
            System.out.println("user found: " + user);
            // Username is taken
            ModelAndView modelAndView = new ModelAndView();
            modelAndView.setViewName("login_error");
            return modelAndView;
        }
    }
}
