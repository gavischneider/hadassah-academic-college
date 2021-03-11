package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@RestController
public class DemoApplication {

    public static void main(String[] args) {

        SpringApplication.run(DemoApplication.class, args);
    }

    @GetMapping("/hello")
    public String sayHello(@RequestParam(value = "myName", defaultValue= "World") String name) {
        return String.format("Hello %s", name);
    }

}

// The @RestController annotation marks the DemoApplication class as a request handler (a REST controller).

// The @GetMapping("/hello") annotation maps the sayHello() method to GET requests for /hello.

// The @RequestParam annotation maps the name method parameter to the myName web request parameter. If you don't provide the myName parameter in your web request, it will default to World.

// After running the application By default, the built-in Apache Tomcat server is listening on port 8080. Open your web browser and go to http://localhost:8080/hello

// To run with parameter: http://localhost:8080/hello?myName=<your name here>