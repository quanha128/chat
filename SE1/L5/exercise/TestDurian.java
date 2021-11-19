package L5.exercise;

public class TestDurian {
    public static void main(String[] args) {
        Durian durian1 = new Durian();
        Durian durian2 = new Durian();

        durian1.peel();
        System.out.println("Durian 1: " + durian1.getState());
        System.out.println("Durian 2: " + durian2.getState());
    }
}
