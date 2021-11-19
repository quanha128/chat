package L6.exercise1;

public class MyStackTest {
    public static void main(String[] args) {
        MyStack<String> s1 = new MyStack<>(10);
        MyStack<Student> s2 = new MyStack<>(10);
        s1.push("Apple");
        s1.push("Banana");
        s1.push("Orange");
        s2.push(new Student("Bob", 10, "001"));
        s2.push(new Student("Alice", 12, "002"));
        System.out.println(s1.pop());
        System.out.println(s2.pop().name);
    }
}
