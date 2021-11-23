package L9.sample9.basic4;

public class User {
    private static int idCounter = 1;

    private int id;
    private String firstName;
    private String familyName;

    public User(String firstName, String familyName) {
        this.id = idCounter;
        this.firstName = firstName;
        this.familyName = familyName;

        idCounter++;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return String.format("%s %s", familyName, firstName);
    }
}