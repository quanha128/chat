package L9.sample9.basic3;

import java.time.LocalDate;

public class User {
    private String firstName;
    private String familyName;

    public User(String firstName, String familyName) {
        this.firstName = firstName;
        this.familyName = familyName;
    }

    public String getName() {
        return String.format("%s %s", familyName, firstName);
    }
}