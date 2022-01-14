package L10;

public class DeliciousFood extends Item implements Eatable{
  public DeliciousFood(String name, int price) {
    super(name, price);
  }

  public int getTaxPrice() {
    return this.price + this.price/5*4;
  }

  public String getTaste() {
    return "Delicious";
  }
}
