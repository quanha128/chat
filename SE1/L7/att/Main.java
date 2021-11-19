package L7.att;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args){
        ArrayList<Student> myList = new ArrayList<>();
        Student alice = new Student("Alice");
        Student bob = new Student("Bob");
        myList.add(alice);
        myList.add(bob);
        for(Student s: myList){
            System.out.println(s.getName());
        }
    }
}