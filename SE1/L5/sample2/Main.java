package L5.sample2;

import L5.sample2.pkg1.Programmer;
import L5.sample2.pkg2.EngineeringStudent;

public class Main {
    public static void main(String[] args) {
        EngineeringStudent st = new EngineeringStudent("1234", "Taro", 1);
        System.out.printf(st.getProfile());
        checkSkill(st);
    }

    private static void checkSkill(Programmer p) {
        if (p.canWritePython()) {
            System.out.println("I can write Python.");
        }
        if (p.canWriteC()) {
            System.out.println("I can write C.");
        }
        if (p.canWriteJava()) {
            System.out.println("I can write Java.");
        }
    }
}
