package L10;

public class Item {
  private String name;
  protected int price;

  public Item(String name, int price) {
    this.name = name;
    this.price = price;
  }

  public int getTaxPrice() {
    return this.price;
  }
}
