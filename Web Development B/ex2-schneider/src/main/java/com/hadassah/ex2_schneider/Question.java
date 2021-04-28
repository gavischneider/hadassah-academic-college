package com.hadassah.ex2_schneider;

/**
 * Question class
 */
public class Question {

    int id;
    String text;
    int answers = 0;

    /**
     *
     * @param id Question ID
     * @param text Question text
     */
    public Question(int id, String text) {
        this.id = id;
        this.text = text;
    }

    /**
     * Default constructor
     */
    public Question() {}

    /**
     *
     * @return Question id
     */
    public int getId() {
        return id;
    }

    /**
     *
     * @param id Set question id
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     *
     * @return Question text
     */
    public String getText() {
        return text;
    }

    /**
     *
     * @param text Set question text
     */
    public void setText(String text) {
        this.text = text;
    }

    /**
     *
     * @return Number of answers
     */
    public int getAnswers() {
        return answers;
    }

    /**
     *
     * @param answers Set the number of answers
     */
    public void setAnswers(int answers) {
        this.answers = answers;
    }
}
