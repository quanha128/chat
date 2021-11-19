package L5.fruit;

public class Orange extends Fruit{
    @Override
    public void peel() {
        this.state = "membraned";
    }
}
