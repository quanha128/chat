package L5.exercise1;

public class Factorial implements Function{
    @Override
    public double evaluate (double x) {
        double res = 1;
        for (int i=2; i<x; i++) {
            res *= i;
        }
        return res;
    }
}
