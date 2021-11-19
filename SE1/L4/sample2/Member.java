package L4.sample2;

public class Member {
    static final String DOMAIN = "@iniad.org";
    String id;
    String name;

    Member(String id, String name) {
        this.id = id;
        this.name = name;
    }

    String getEmail() {
        return this.id + DOMAIN;
    }

    String getProfile() {
        StringBuffer sb = new StringBuffer();
        sb.append("ID: ").append(id).append("\n");
        sb.append("Name: ").append(name).append("\n");
        String email = getEmail();
        sb.append("email: ").append(email).append("\n");
        return sb.toString();
    }
}
