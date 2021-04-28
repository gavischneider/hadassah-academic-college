package com.hadassah.ex2_schneider;

/**
 * Answer class
 */
public class Answer {

    int question;
    String text;
    String user;

    /**
     *
     * @param question Question ID
     * @param text Answer text
     * @param user Answers author
     */
    public Answer(int question, String text, String user) {
        this.question = question;
        this.text = text;
        this.user = user;
    }

    /**
     *  Default constuctor
     */
    public Answer() {}

    /**
     *
     * @return Question ID
     */
    public int getQuestion() {
        return question;
    }

    /**
     *
     * @param question Set question ID
     */
    public void setQuestion(int question) {
        this.question = question;
    }

    /**
     *
     * @return Answer text
     */
    public String getText() {
        return text;
    }

    /**
     *
     * @param text Set answer text
     */
    public void setText(String text) {
        this.text = text;
    }

    /**
     *
     * @return Answers author
     */
    public String getUser() {
        return user;
    }

    /**
     *
     * @param user Set answers author
     */
    public void setUser(String user) {
        this.user = user;
    }
}
