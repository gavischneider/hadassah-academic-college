package com.example.ex4.models;

import lombok.Data;
import javax.persistence.*;
import javax.validation.constraints.NotEmpty;

/**
 * User model
 */
@Entity
@Table(name = "user")
@Data
public class User {
    /**
     * id - Auto generated id
     * username - users name
     * online - online/offline status
     */
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "id")
    private Long id;

    @NotEmpty(message = "Name is mandatory")
    @Column(name = "username", unique=true)
    String username;

    @Column(name = "online")
    boolean online;

    /**]
     * Default constructor
     */
    public User(){
    }

    /**
     *
     * @param username - name
     */
    public User(String username){
        this.username = username;
        this.online = true;
    }

    /**
     *
     * @return - name
     */
    public String getUsername() {
        return username;
    }

    /**
     *
     * @param username - name
     */
    public void setUsername(String username) {
        this.username = username;
    }

}
