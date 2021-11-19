package L4.sample2;

public class Student extends Member {
    int grade;

    Student(String id, String name, int grade) {
        super(id, name);
        this.grade = grade;
    }

    @Override
    String getProfile() {
        StringBuffer sb = new StringBuffer();
        sb.append("----- Student -----\n");
        sb.append(super.getProfile());
        sb.append("Grade: ").append(grade).append("\n");
        return sb.toString();
    }
}
