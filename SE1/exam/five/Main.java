package exam.five;

public class Main {
    public static void main(String[] args) {
        Button btn = new Button("My button");
        btn.print();
        for(int i = 0; i < 10; i++) {
            btn.click();
        }
        btn.print();
    }
}