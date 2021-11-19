package L5.att;

public class Car implements Vehicle {
    private int seat;

    @Override
    public void start() {
        System.out.println("Car starts ...");
    }

    @Override
    public void stop() {
        System.out.println("Car stops ...");
    }

    public Car(int seat) {
        this.seat = seat;
    }

    public int getSeat() {
        return this.seat;
    }
}
