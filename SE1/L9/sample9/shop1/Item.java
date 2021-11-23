package L9.sample9.shop1;

public class Item {
    private User seller;
    private String name;
    private int price;

    public Item(User seller, String name, int price) {
        this.seller = seller;
        this.name = name;
        this.price = price;
    }

    public User getSeller() {
        return seller;
    }

    public String getName() {
        return name;
    }

    public int getPrice() {
        return price;
    }
}