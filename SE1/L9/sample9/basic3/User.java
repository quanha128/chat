package L9.sample9.basic3;

import java.time.LocalDate;

public class User {
    private String firstName;
    private String familyName;
    private LocalDate birthday;
    private static int idCounter = 1;
    private int id;

    public User(String firstName, String familyName, LocalDate birthday) {
        this.firstName = firstName;
        this.familyName = familyName;
        this.birthday = birthday;
    }

    public String getName() {
        return String.format("%s %s", familyName, firstName);
    }

    public int getAge(LocalDate when) {
      return birthday.until(when).getYears();
    }
}