package L9.sample9.shop4;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileLogger implements Logger{
  private File file;

  public FileLogger(File file) {
    this.file = file;
  }

  public void purchase(Customer customer, Item item) {
    try {
      FileWriter fileWriter = new FileWriter(file, true);
      fileWriter.write(String.format("[Purchase] %s: %s(%d yen).\n", customer.getName(), item.getName(), item.getPrice()));
      fileWriter.close();
    } catch(IOException e) {
      System.out.println("write error");
    }
  }

  public void balance(User user) {
    try {
      FileWriter fileWriter = new FileWriter(file, true);
      fileWriter.write(String.format("[Balance] %s: %d yen.\n", user.getName(), user.getBalance()));
      fileWriter.close();
    } catch(IOException e) {
      System.out.println("write error");
    }
  }

  public void error(User user, String error) {
    try {
      FileWriter fileWriter = new FileWriter(file, true);
      fileWriter.write(String.format("[Error] %s: %s.\n", user.getName(), error));
      fileWriter.close();
    } catch(IOException e) {
      System.out.println("write error");
    }
  }
}
