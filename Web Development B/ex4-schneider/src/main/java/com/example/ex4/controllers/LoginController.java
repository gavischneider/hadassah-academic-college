package com.example.ex4.controllers;

import com.example.ex4.models.User;
import com.example.ex4.models.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;
import javax.servlet.http.HttpServletRequest;

/**
 * LoginController - Controls authentication
 */
@Controller
public class LoginController {

    @Autowired
    private UserRepository userRepository;
    private UserRepository getRepo() {
        return userRepository;
    }

    /**
     *
     * @param request - Incoming request object
     * @return - Login page, or redirect to index if a user is already logged in
     */
    @GetMapping("/login")
    public Object loginPage(HttpServletRequest request) {
        String username = (String) request.getSession().getAttribute("username");
        if(username != null) {
            return "redirect:/index";
        }

        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("login");
        return modelAndView;
    }

    /**
     *
     * @param username - Users input
     * @param request - Incoming request object
     * @return - Redirects to index, or returns an error page if username is already taken
     */
    @PostMapping("/login")
    public Object login(@RequestParam String username, HttpServletRequest request){
        User user = getRepo().findByUsername(username);
        if(user == null){
            // Username is available, add name to session
            request.getSession().setAttribute("username", username);

            // Add user to database
            User newUser = new User(username);
            getRepo().save(newUser);
            return "redirect:/index";
        } else {
            System.out.println("user found: " + user);
            // Username is taken
            ModelAndView modelAndView = new ModelAndView();
            modelAndView.setViewName("login_error");
            return modelAndView;
        }
    }

    /**
     *
     * @param request - Incoming request object
     */
    @PostMapping("/logout")
    public void logout(HttpServletRequest request) {
        User user = getRepo().findByUsername((String) request.getSession().getAttribute("username"));
        request.getSession().invalidate();
        getRepo().delete(user);
    }
}
