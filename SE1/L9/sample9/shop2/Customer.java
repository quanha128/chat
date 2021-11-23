package L9.sample9.shop2;

public class Customer extends User {
    public Customer(String name) {
        super(name);
    }

    public void withdraw(int amount) {
        balance -= amount;
    }   
}