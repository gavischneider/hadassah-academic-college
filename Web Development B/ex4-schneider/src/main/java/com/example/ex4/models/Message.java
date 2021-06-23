package com.example.ex4.models;

import lombok.Data;
import org.hibernate.annotations.CreationTimestamp;
import org.springframework.data.annotation.CreatedBy;
import javax.persistence.*;
import javax.validation.constraints.NotEmpty;
import java.util.Date;

/**
 * Message model
 */
@Entity
@Table(name = "message")
@Data
public class Message {
    /**
     * id - Auto generated ID
     * created - Auto generated creation date
     * user - message author
     * body - message content
     */
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "id")
    private Long id;

    @CreationTimestamp
    @Column(name = "created")
    private Date created;

    @CreatedBy
    @Column(name = "user", nullable = false, updatable = false)
    private String user;

    @NotEmpty(message = "Message body is mandatory")
    @Column(name = "body")
    String body;

    /**
     *
     * @param user - name
     * @param body - message body
     */
    public Message(String user, String body){
        this.user = user;
        this.body = body;
    };

    /**
     * Default constructor
     */
    public Message(){};

    /**
     *
     * @return - user
     */
    public String getUser() {
        return user;
    }

    /**
     *
     * @param user - user
     */
    public void setUser(String user) {
        this.user = user;
    }
}
