package L7.quiz;

public class Apple extends Fruit implements Sellable{
    int price;
    public Apple(double weight, int price) {
        super(weight);
        this.price = price;
    }

    @Override
    public int getPrice() {
        return this.price;
    }

    @Override
    public String getColor() {
        return "Red";
    }
}
