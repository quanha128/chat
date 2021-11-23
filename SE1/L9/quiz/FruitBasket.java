package L9.quiz;

import java.util.ArrayList;

public class FruitBasket {
    ArrayList<Fruit> basket;
    public FruitBasket() {
        this.basket = new ArrayList<Fruit>();
    }

    public void add(Fruit fruit) {
        this.basket.add(fruit);
    }

    public void print() {
        for (Fruit fruit: basket) {
            System.out.println(fruit.getColor());
        }
    }
}
