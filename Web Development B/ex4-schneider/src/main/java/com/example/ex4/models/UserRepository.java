package com.example.ex4.models;

import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;

/**
 * User repository
 */
public interface UserRepository extends JpaRepository<User, Long> {
    User findByUsername(String username);
    List<User> getAllByOnline(boolean online);
    List<User> findByUsernameContaining(String username);
}
