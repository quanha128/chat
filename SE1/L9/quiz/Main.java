package L9.quiz;

public class Main {
    public static void main(String[] args) {
        FruitBasket fb = new FruitBasket();
        fb.add(new Apple());
        fb.add(new Grape());
        fb.add(new Apple());
        fb.print();
    }
}
