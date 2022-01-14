package L14;

public class Calculator {
  public Calculator() {
  }

  public int permutation(int n, int k) {
      if(n <= 0) {
          throw new IllegalArgumentException();
      }
      if(n < k) {
          throw new IllegalArgumentException();
      }

      int result = 1;
      for(int i = 0; i < k; i++) {
          result *= (n - i);
      }
      return result;
  }
}
