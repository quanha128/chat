package L7.sample2;

import L7.sample2.pkg1.Member;
import L7.sample2.pkg2.Student;
import L7.sample2.pkg2.Teacher;
import L7.sample2.pkg2.MemberList;
public class Main {
    public static void main(String[] args) {
        MemberList ml = new MemberList();
        ml.add(new Student("1234", "Taro", 1));
        ml.add(new Student("4231", "Jiro", 2));
        System.out.println(ml.count());

        Member m1 = ml.get("1234");
        System.out.println(m1.getProfile());

        ml.remove("1234");
        ml.add(new Teacher("1000", "Inoue", "Professor"));
        System.out.println(ml.count());

        Member m2 = ml.get("1000");
        System.out.println(m2.getProfile());
    } 
}