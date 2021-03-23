package hadassah;

public class InvalidCommandException extends Exception {

    public InvalidCommandException(String message) {
        super(message);
    }

    public InvalidCommandException() {
    }
}
