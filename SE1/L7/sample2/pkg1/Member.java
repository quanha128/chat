package L7.sample2.pkg1;

public abstract class Member implements Comparable<Member>{
    protected static final String DOMAIN = "@iniad.org";
    protected String id;
    protected String name;

    public Member(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getEmail() {
        return this.id + DOMAIN;
    }

    public String getProfile() {
        StringBuffer sb = new StringBuffer();
        sb.append("ID: ").append(id).append("\n");
        sb.append("Name: ").append(name).append("\n");
        String email = getEmail();
        sb.append("email: ").append(email).append("\n");
        if (canReserveRoom()) {
            sb.append("Room: OK").append("\n");
        } else {
            sb.append(("Room: NG")).append("\n");
        }
        return sb.toString();
    }

    abstract public boolean canReserveRoom();

    @Override
    public int compareTo(Member m) {
        return id.compareTo(m.id);
    }

    public String getId() {
        return this.id;
    }
}
