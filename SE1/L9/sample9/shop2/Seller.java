package L9.sample9.shop2;

public class Seller extends User {
    public Seller(String name) {
        super(name);
    }

    public void transfer(int amount) {
        balance += amount;
    }   
}