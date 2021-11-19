package L5.sample2.pkg2;

import L5.sample2.pkg1.Programmer;

public class EngineeringTeacher extends Teacher implements Programmer{
    public EngineeringTeacher(String id, String name, String title) {
        super(id, name, title);
    }

    @Override
    public boolean canWritePython() {
        return true;
    }

    @Override
    public boolean canWriteC() {
        return true;
    }

    @Override
    public boolean canWriteJava() {
        return true;
    }
}
