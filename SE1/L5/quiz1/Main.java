package L5.quiz1;

public class Main {
    public static void main(String[] args) {
        CourseNameCard n1 = new CourseNameCard("Taro", "Engineering");
        CourseNameCard n2 = new CourseNameCard("Jiro", "Business");
        System.out.println(n1.getLabel());
        System.out.println(n1.getCourse());
        System.out.println(n2.getLabel());
        System.out.println(n2.getCourse());
    }
}