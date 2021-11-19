package L5.exercise;

public class Fruit {
    public String state = "skinned";

    public void peel() {
        this.state = "peeled";
    }

    public String getState() {
        return this.state;
    }
}
