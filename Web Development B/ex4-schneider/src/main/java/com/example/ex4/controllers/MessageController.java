package com.example.ex4.controllers;

import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import com.example.ex4.models.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Map;

@RestController
public class MessageController {
    @Autowired
    MessageRepository messageRepository;

    private MessageRepository getRepo(){
        return messageRepository;
    }

    // Get all messages
    @GetMapping("/message/all")
    public List<Message> getAllMessages() {
        return getRepo().findAll();
    }

    // Get the five latest messages
    @GetMapping("/message/last-five")
    public List<Message> getLastMessages() {
        return getRepo().findTop5ByOrderByCreatedDesc();
    }

    // Add a new message
    @PostMapping("/message/add")
    public void addMessage(@RequestBody Map<String, String> newUser){
        System.out.println(newUser);
        Message message = new Message(newUser.get("user"), newUser.get("body"));
        getRepo().save(message);

        ////////
        //ModelAndView modelAndView = new ModelAndView();
        //modelAndView.setViewName("index");
        //return modelAndView;
    }
}
