package L7.sample2.pkg2;

import L7.sample2.pkg1.*;

public class Teacher extends Member {
    String title;

    public Teacher(String id, String name, String title) {
        super(id, name);
        this.title = title;
    }

    @Override
    public String getEmail() {
        return this.name + DOMAIN;
    }

    @Override
    public String getProfile() {
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
