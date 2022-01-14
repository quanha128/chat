package L10;

public class Book extends Item{
  public Book(String name, int price) {
    super(name, price);
  }

  @Override
  public int getTaxPrice() {
    // TODO Auto-generated method stub
    return this.price + this.price/10;
  }
}
