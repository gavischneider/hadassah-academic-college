package com.example.ex4.controllers;

import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

@Controller
public class MessageController {
    @Autowired
    MessageRepository messageRepository;

    private MessageRepository getRepo(){
        return messageRepository;
    }

    @GetMapping("message/last-five")
    public List<Message> getLastMessages() {
        return getRepo().findTop5ByOrderByDateDesc();
    }

    
}
