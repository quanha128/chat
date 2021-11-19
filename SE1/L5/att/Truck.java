package L5.att;

public class Truck implements Vehicle{@Override
    public void start() {
        System.out.println("Truck starts ...");
    }

    @Override
    public void stop() {
        System.out.println("Truck stops ...");
    }

    public Truck() {}
}
