package com.example.ex4.controllers;

import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class SearchController {
    @Autowired
    UserRepository userRepository;

    @Autowired
    MessageRepository messageRepository;

    private UserRepository getUserRepo() {
        return userRepository;
    }

    private MessageRepository getMessageRepo(){ return messageRepository; }

    // Search for users by name
    @GetMapping("/search/user")
    public List<User> searchUsers(@RequestParam String query){
        return getUserRepo().getAllByUsername(query);
    }

    // Search for messages by body
    @GetMapping("/search/message/body")
    public List<Message> searchMessagesByBody(@RequestParam String query){
        return getMessageRepo().getAllByBody(query);
    }

    // Search for messages by user
    @GetMapping("/search/message/user")
    public List<Message> searchMessagesByUser(@RequestParam String query){
        return getMessageRepo().getAllByUser(query);
    }
}
