package L4;

public class Book {
    String name;
    Author author;
    int price;

    public Book(String nam, Author auth) {
        this.name = nam;
        this.author = auth;
    }

    public Book(String nam, Author auth, int pri) {
        this.name = nam;
        this.author = auth;
        this.price = pri;
    }

    public String getName() {
        return this.name;
    }

    public String getAuthor() {
        return this.author.toString();
    }

    public int getPrice() {
        return this.price;
    }

    public void setPrice(int newp) {
        this.price = newp;
    }
}
