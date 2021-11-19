package L5.sample2.pkg2;

public class Teacher extends Member {
    String title;

    Teacher(String id, String name, String title) {
        super(id, name);
        this.title = title;
    }

    @Override
    String getEmail() {
        return this.name + DOMAIN;
    }

    @Override
    String getProfile() {
        StringBuffer sb = new StringBuffer();
        sb.append("----- Teacher -----\n");
        sb.append(super.getProfile());
        sb.append("Title: ").append(title).append("\n");
        return sb.toString();
    }

    @Override
    public boolean canReserveRoom() {
        return true;
    }
}
