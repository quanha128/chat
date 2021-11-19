package L5.fruit;

public class TestFruits {
    public static void main(String[] args) {
        Durian durian = new Durian();
        Orange orange = new Orange();
        Apple apple = new Apple();

        System.out.println("Durian: "+durian.getState());
        System.out.println("Orange: "+orange.getState());
        System.out.println("Apple: "+apple.getState());

        durian.peel();
        orange.peel();
        apple.peel();

        System.out.println("Durian: "+durian.getState());
        System.out.println("Orange: "+orange.getState());
        System.out.println("Apple: "+apple.getState());
    }
}
