package L10.sample10.observer1;

public class MyObserver implements Observer {
    public MyObserver() {
    }

    public void update(Subject subject) {
        String status = subject.getStatus();
        System.out.printf("Status: %s\n", status);
    }
}