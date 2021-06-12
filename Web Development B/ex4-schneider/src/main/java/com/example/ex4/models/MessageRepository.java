package com.example.ex4.models;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface MessageRepository extends JpaRepository<Message, Long> {
    //@Override
    Message getById(Long aLong);

    List<Message> findTop5ByOrderByDateDesc();
}
