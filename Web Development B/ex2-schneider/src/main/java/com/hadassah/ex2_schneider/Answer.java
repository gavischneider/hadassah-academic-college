package com.hadassah.ex2_schneider;

public class Answer {

    int id;
    int question;
    String text;
    String user;

    public Answer(int id, int question, String text, String user) {
        this.id = id;
        this.question = question;
        this.text = text;
        this.user = user;
    }

    public Answer() {}

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getQuestion() {
        return question;
    }

    public void setQuestion(int question) {
        this.question = question;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }
}
