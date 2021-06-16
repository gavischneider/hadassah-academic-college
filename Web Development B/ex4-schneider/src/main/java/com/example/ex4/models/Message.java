package com.example.ex4.models;

import lombok.Data;
import org.springframework.data.annotation.CreatedBy;
import org.springframework.data.annotation.CreatedDate;

import javax.persistence.*;
import javax.validation.constraints.NotEmpty;
import java.util.Date;

@Entity
@Table(name = "message")
@Data
public class Message {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "id")
    private Long id;

    @CreatedDate
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "created")
    private Date created;

    @CreatedBy
    @Column(name = "user", nullable = false, updatable = false)
    private String user;

    @NotEmpty(message = "Message body is mandatory")
    @Column(name = "body")
    String body;

    public Message(String user, String body){
        this.user = user;
        this.body = body;
    };

    public Message(){};

    public Long getId() {
        return id;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    public Date getCreated() {
        return created;
    }

    public String getBody() {
        return body;
    }

    public void setBody(String body) {
        this.body = body;
    }
}
