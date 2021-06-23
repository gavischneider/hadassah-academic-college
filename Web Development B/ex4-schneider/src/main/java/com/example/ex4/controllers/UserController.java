package com.example.ex4.controllers;

import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import java.util.List;

/**
 * User Controller
 */
@RestController
public class UserController {
    @Autowired
    private UserRepository userRepository;

    private UserRepository getRepo() {
        return userRepository;
    }

    /**
     *
     * @return - All online users
     */
    @GetMapping("/user/online")
    public List<User> getOnlineUsers(){
        return getRepo().getAllByOnline(true);
    }
}
