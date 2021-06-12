package com.example.ex4.controllers;

import com.example.ex4.models.MessageRepository;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class HomeController {
    @Autowired
    UserRepository userRepository;

    @Autowired
    MessageRepository messageRepository;

    private UserRepository getUserRepo() {
        return userRepository;
    }

    private MessageRepository getMessageRepo(){ return messageRepository; }

    @GetMapping("index")
    //public ModelAndView homePage() {
      //  ModelAndView modelAndView = new ModelAndView();
        //modelAndView.setViewName("index");
        //return modelAndView;
    //}

    // If user is logged in --> Index (Get 5 latest messages, users that are online)
    // If user is NOT logged in --> Login
    public String index(){
        return "redirect:/login";
    }
}
