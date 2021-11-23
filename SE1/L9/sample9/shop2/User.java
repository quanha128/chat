package L9.sample9.shop2;

public class User {
    private String name;
    protected int balance = 0;

    public User(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
    
    public void charge(int amount) {
        balance += amount;
    }

    public int getBalance() {
        return balance;
    }
}