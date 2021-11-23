package L9.sample9.shop4;

abstract public class User {
    protected String name;
    protected int balance = 0;

    public User(String name) {
        this.name = name;
    }
    
    public void charge(int amount) {
        balance += amount;
    }

    public int getBalance() {
        return balance;
    }

    abstract public String getName();
}