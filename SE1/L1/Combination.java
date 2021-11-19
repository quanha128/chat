package L1;
public class Combination {
    public static int factorial(int n) {
        int i = 1;
        int res = 1;
        while (i <= n) {
            res *= i;
            i++;
        }
        return res;
    }
    public static int combination(int n, int r) {
        return factorial(n)/(factorial(r)*factorial(n-r));
    }

    public static void main(String[] args) {
        int n = 5;
        int r = 3;
        int c = combination(n, r);
        System.out.printf("C(%d, %d) = %d\n", n, r, c);
    }
}