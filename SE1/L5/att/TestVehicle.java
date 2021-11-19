package L5.att;

public class TestVehicle {
    public static void main(String[] args) {
        Vehicle car = new Car(4);
        Vehicle truck = new Truck();

        car.start();
        car.stop();
        truck.start();
        truck.stop();
    }
}