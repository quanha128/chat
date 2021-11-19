package exam.five;

public class Button extends Component implements Clickable{
    private int cnt=0;

    public Button(String label) {
        super(label);
    }

    @Override
    public void print() {
        System.out.printf("Button: %s (%d clicks)\n", label, cnt);
    }

    @Override
    public void click() {
        cnt++;
    }
}
