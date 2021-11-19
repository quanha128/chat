package L3;

public class TestLogger {
    public static void main(String[] args) {
        try {
            MyLogger log1 = new MyLogger("log1.txt");
            MyLogger log2 = new MyLogger("log2.txt");
            MyLogger log3 = new MyLogger("log3.txt");
            log1.write("This is log1 content");
            log2.write("This is log2 content");
            log3.write("This is log3 content");
            // log1 = null;
            // log2 = null;
            log3 = null;
            MyLogger.free();
            // MyLogger.free();
            // MyLogger.free();
            // MyLogger.free();
            MyLogger log4 = new MyLogger("log4.txt");
            log4.write("This is log4 content");
        } catch(UnsupportedOperationException e) {
            System.out.println("Amount of instances exceeded");
        } catch(Error e) {
            System.out.println("No existing instance");
        }
    }
}