package com.example.ex4.controllers;

import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
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

    @GetMapping("/search")
    public ModelAndView searchPage(Model model, HttpServletRequest request) {
        String username = (String) request.getSession().getAttribute("username");
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("search");
        modelAndView.addObject("user", username);
        return modelAndView;
    }

    // Search for users by name
    @PostMapping("/search/user")
    public List<User> searchUsers(@RequestParam String query){
        return getUserRepo().getAllByUsername(query);
    }

    // Search for messages by body
    @PostMapping("/search/message/body")
    public List<Message> searchMessagesByBody(@RequestParam String query){
        return getMessageRepo().getAllByBody(query);
    }

    // Search for messages by user
    @PostMapping("/search/message/user")
    public List<Message> searchMessagesByUser(@RequestParam String query){
        return getMessageRepo().getAllByUser(query);
    }
}
