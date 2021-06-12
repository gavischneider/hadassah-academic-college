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
    @Column(name = "created", nullable = false, updatable = false)
    private Date created;

    @CreatedBy
    @ManyToOne
    @JoinColumn(name = "user", nullable = false, updatable = false)
    private User user;

    @NotEmpty(message = "Message body is mandatory")
    @Column(name = "body")
    String body;

    String username;

    public Message(User user, String body){
        this.user = user;
        this.body = body;
        this.username = user.getUsername();
    };

    public Message(){};

    public Long getId() {
        return id;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
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

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }
}
