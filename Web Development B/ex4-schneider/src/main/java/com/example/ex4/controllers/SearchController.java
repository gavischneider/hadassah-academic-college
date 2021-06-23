package com.example.ex4.controllers;
import com.example.ex4.models.Message;
import com.example.ex4.models.MessageRepository;
import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import java.util.List;

/**
 * Search Controller - All routes that involve search
 */
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

    /**
     *
     * @param query - Users search query
     * @return - Users whose names match the query
     */
    @GetMapping("/search/user")
    public List<User> searchUsers(@RequestParam String query){
        return getUserRepo().findByUsernameContaining(query);
    }

    /**
     *
     * @param query - Users search query
     * @return - Messages whose body match the query
     */
    @GetMapping("/search/message/body")
    public List<Message> searchMessagesByBody(@RequestParam String query){
        return getMessageRepo().findByBodyContaining(query);
    }

    /**
     *
     * @param query - Users search query
     * @return - Messages whose sender (username) matches the query
     */
    @GetMapping("/search/message/user")
    public List<Message> searchMessagesByUser(@RequestParam String query){
        return getMessageRepo().findByUserContaining(query);
    }
}
