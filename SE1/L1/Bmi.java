package L1;
public class Bmi {
    public static void printRisk(int age, double h, double w) {
        double bmi = w/(h*h/10000);
        System.out.println("Your BMI is: " + bmi);
        System.out.printf("Your risk: ");
        if (age < 45) {
            if (bmi < 22) System.out.println("Low");
            else System.out.println("Medium");
        } else {
            if (bmi < 22) System.out.println("Medium");
            else System.out.println("High");
        }
    }

    public static void main(String[] args) {
        int age = 30;
        double h = 170.0;
        double w = 70.0;

        printRisk(age, h, w);
    }
}