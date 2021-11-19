package L5.exercise5;

public class FreshFood extends Product{
    private final double tax = 0.08;

    public FreshFood(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public double getTaxIncludedPrice() {
        return this.price * (1+tax);
    }
}
