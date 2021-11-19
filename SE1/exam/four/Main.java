package exam.four;

public class Main {
    public static void main(String[] args) {
        TextBook b = new TextBook("Introduction to INIAD", "Programming", 1000);
        System.out.println(b.getTitle());
        System.out.println(b.getPrice());
    }
}