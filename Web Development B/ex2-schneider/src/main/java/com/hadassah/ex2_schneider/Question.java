package com.hadassah.ex2_schneider;

public class Question {

    int id;
    String text;
    int answers = 0;

    public Question(int id, String text) {
        this.id = id;
        this.text = text;
    }

    public Question() {}

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public int getAnswers() {
        return answers;
    }

    public void setAnswers(int answers) {
        this.answers = answers;
    }
}
