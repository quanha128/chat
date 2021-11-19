package L4;
public class Author {
    String name;
    String email;

    public Author(String n, String e) {
        this.name = n;
        this.email = e;
    }

    public String getName() {
        return this.name;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String input) {
        this.email = input;
    }

    public String toString() {
        String res = String.format("Author [name=%s, email=%s]", this.name, this.email);
        return res;
    }
}
