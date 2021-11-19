package L4;

public class NameCard {
    final String firstName;
    final String familyName;
    private static int cnt=1;
    final int id;

    public NameCard(String firstName, String familyName) {
        this.id = cnt++;
        this.firstName = firstName;
        this.familyName = familyName;
    }

    public String getLabel() {
        String res = String.format("No. %d: %s %s", id, firstName, familyName);
        return res;
    }
}
