package L1;
import java.util.Scanner;
import java.lang.NumberFormatException;

public class Binary {
    public static void main(String[] args) {
        try {
            System.out.println("Number to be converted: ");
            Scanner inp = new Scanner(System.in);
            int num = Integer.valueOf(inp.nextLine());
            System.out.println("Check: " + Integer.toBinaryString(num));
            int r;
            String res = "";
            do {
                r = num % 2;
                res = String.valueOf(r) + res;
                num /= 2;
            } while (num != 0);
            System.out.println("Result: " + res);
            inp.close();
        } catch (NumberFormatException ex) {
            System.out.println("Please input integer");
        } finally {
            System.out.println("End!");
        }
    }
}