package L5.attendance;

public class Main {
    public static void main(String[] args) {
        Student st = new Student();
        st.age = 3;
        Teacher t = new Teacher();
        t.age = 133;
        System.out.println(st.getAge());
        System.out.println(t.getAge());
    }
}
