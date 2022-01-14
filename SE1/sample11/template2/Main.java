package sample11.template2;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        ActivityManager manager = ActivityManager.getInstance();
        manager.addActivity(new EchoActivity());
        manager.addActivity(new QuizActivity());

        manager.execute();
    }
}
