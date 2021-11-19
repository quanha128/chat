package L5.exercise2;

public class Main {
    public static void main(String[] args) {
        Human h = new Human();
        Dog d = new Dog();
        Cat c = new Cat();

        h.run();
        d.run();
        c.run();

        System.out.println(h.getStomach());
        System.out.println(d.getStomach());
        System.out.println(c.getStomach());

        System.out.println(d.bark());
        System.out.println(c.bark());
        System.out.println(h.talk());
    }
}
