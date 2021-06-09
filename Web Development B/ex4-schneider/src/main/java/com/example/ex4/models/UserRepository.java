package com.example.ex4.models;

import com.example.ex4.models.User;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;


public interface UserRepository extends JpaRepository<User, Long> {
    User findByUsername(String username);
    List<User> findFirst10ByOrderByUsernameDesc();
}
