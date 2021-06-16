package com.example.ex4.controllers;

import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

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
    public void addMessage(@RequestParam String user, @RequestParam String body){
        Message message = new Message(user, body);
        getRepo().save(message);

        ////////
        //ModelAndView modelAndView = new ModelAndView();
        //modelAndView.setViewName("index");
        //return modelAndView;
    }
}
