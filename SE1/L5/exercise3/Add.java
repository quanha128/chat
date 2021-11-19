package L5.exercise3;

public abstract class Add implements Calc{
    @Override
    public int add(int x) {
        return x + Calc.value;
    }
}
