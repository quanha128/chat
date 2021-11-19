package exam.four;

public class Book {
    protected final String title;
    protected final int price;

    public Book(String title, int price) {
        this.title = title;
        this.price = price;
    }

    public String getTitle() {return title;}

    public int getPrice() {return price;}
}
