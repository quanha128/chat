package exam.five;

public abstract class Component {
    protected String label;

    public Component(String label) {
        this.label = label;
    }

    public String getLabel() {return label;}

    public abstract void print();
}
