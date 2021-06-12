package com.example.ex4;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@SpringBootApplication
@Controller
public class Ex4Application {

    public static void main(String[] args) {
        SpringApplication.run(Ex4Application.class, args);

    }

    @GetMapping("/")
    public String index(){
        return "redirect:/index";
    }
}
