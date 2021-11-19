package L5.sample2.pkg2;

public class Student extends Member {
    protected int grade;

    Student(String id, String name, int grade) {
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
