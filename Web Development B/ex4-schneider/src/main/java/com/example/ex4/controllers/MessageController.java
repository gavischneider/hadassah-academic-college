package com.example.ex4.controllers;

import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.List;
import java.util.Map;

/**
 * Message Controller
 */
@RestController
public class MessageController {
    @Autowired
    MessageRepository messageRepository;

    private MessageRepository getRepo(){
        return messageRepository;
    }

    /**
     *
     * @return - All messages
     */
    @GetMapping("/message/all")
    public List<Message> getAllMessages() {
        return getRepo().findAll();
    }

    /**
     *
     * @return - Five most recent messages
     */
    @GetMapping("/message/last-five")
    public List<Message> getLastMessages() {
        return getRepo().findTop5ByOrderByCreatedDesc();
    }

    /**
     *
     * @param newUser - Holds the user and body params to create a new message
     */
    @PostMapping("/message/add")
    public void addMessage(@RequestBody Map<String, String> newUser){
        System.out.println(newUser);
        Message message = new Message(newUser.get("user"), newUser.get("body"));
        getRepo().save(message);
    }
}
