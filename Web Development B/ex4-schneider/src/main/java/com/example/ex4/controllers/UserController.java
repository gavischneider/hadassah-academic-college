package com.example.ex4.controllers;

import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class UserController {
    @Autowired
    private UserRepository userRepository;

    private UserRepository getRepo() {
        return userRepository;
    }

    // Returns all online users
    @GetMapping("/online-users")
    public List<User> getOnlineUsers(){
        return getRepo().getAllByOnline(true);
    }
}
