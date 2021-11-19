package exam;

public class Label {
    public static final String HEADER = "--- INIAD ---\n";
    private int id;
    private String name;

    public Label(String name) {
        this.name = name;
        id++;
    }

    public String getDisplay() {
        return String.format("%s[%d] %s", HEADER, id, name);
    }
}
