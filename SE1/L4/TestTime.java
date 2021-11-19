package L4;

public class TestTime {
    public static void main(String[] args) {
        Time time1 = new Time(16,7,30);
        time1.setHour(time1.hour + 1);
        System.out.println(time1.getCurrentTime());
    }
}
