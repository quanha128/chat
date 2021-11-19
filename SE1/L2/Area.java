package L2;

import java.util.Random;

public class Area {
    public static void main(String[] args) {
        Random rand = new Random();
        int r = rand.nextInt(10);
        double res = r * r * Math.PI;
        System.out.printf("The area of a circle with a radius of %d is %f\n", r, res);
    }
}
