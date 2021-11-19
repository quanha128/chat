package L6.quiz;

public final class AdvancedMachine extends Machine {
    private static int total;

    public AdvancedMachine (String model, int price) {
        super(model, price);
        total += price;
    }

    public static int getTotalPrice() {
        return AdvancedMachine.total;
    }

    public int getPrice() {
        return this.price + this.price/10;
    }
}