package L7.sample2.pkg2;

import L7.sample2.pkg1.*;

public class Student extends Member {
    int grade;

    public Student(String id, String name, int grade) {
        super(id, name);
        this.grade = grade;
    }

    @Override
    public String getProfile() {
        StringBuffer sb = new StringBuffer();
        sb.append("----- Student -----\n");
        sb.append(super.getProfile());
        sb.append("Grade: ").append(grade).append("\n");
        return sb.toString();
    }

    @Override
    public boolean canReserveRoom() {
        return false;
    }
}
