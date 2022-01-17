package exam;

public class Label {
    public static final String HEADER = "--- INIAD ---\n";
    private int id;
    private String name;
    private static int cnt = 1;

    public Label(String name) {
        this.name = name;
        this.id = cnt++;
    }

    public String getDisplay() {
        return String.format("%s[%d] %s", HEADER, id, name);
    }
}
