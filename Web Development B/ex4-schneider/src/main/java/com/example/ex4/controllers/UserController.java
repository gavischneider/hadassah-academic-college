package com.example.ex4.controllers;

import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

@Controller
public class UserController {
    @Autowired
    private UserRepository userRepository;

    private UserRepository getRepo() {
        return userRepository;
    }

    @GetMapping("online-users")
    public List<User> getOnlineUsers(){
        return getRepo().getAllByOnline(true);
    }
}
