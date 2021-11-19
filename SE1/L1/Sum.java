package L1;
import java.util.Scanner;
import java.lang.NumberFormatException;

public class Sum {
    public static void main(String... args) {
        try {
            System.out.println("Input two numbers");
            Scanner in1 = new Scanner(System.in);
            int inp1 = Integer.valueOf(in1.nextLine());
            Scanner in2 = new Scanner(System.in);
            int inp2 = Integer.valueOf(in2.nextLine());
            System.out.printf("%d plus %d = %d\n", inp1, inp2, inp1+inp2);
            in1.close();
            in2.close();
        } catch (NumberFormatException ex) {
            System.out.println("Please input integer");
        } finally {
            System.out.println("End!");
        }
    }
}
