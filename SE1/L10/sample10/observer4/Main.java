package L10.sample10.observer4;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        SensorReader sr = new SensorReader("USER_NAME","PASSWORD");
        sr.execute("3205");
    }
}