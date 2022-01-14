package L14;

import java.util.ArrayList;
import java.util.List;

public class Temperature {
  private List<Observer> observers = new ArrayList<Observer>();
  private int temperature;

  public Temperature() {
  }

  public int get() {
    return temperature;
  }

  public void set(int temperature) {
    this.temperature = temperature;
    notifyObserver();
  }

  public void addObserver(Observer observer) {
    observers.add(observer);
  }

  public void notifyObserver() {
    for(Observer observer : observers) {
      observer.update(this);
    }
  }
}
