package L9.sample9.shop3;

public class Seller extends User {
    private String shopName;

    public Seller(String name, String shopName) {
        super(name);
        this.shopName = shopName;
    }

    public void transfer(int amount) {
        balance += amount;
    }

    public String getName() {
        return String.format("%s(%s)", shopName, name);
    }
}