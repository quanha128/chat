package L4;

public class Time {
    int hour;
    private int minute;
    private int second;

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public int getHour() {return this.hour;}

    public int getMinute() {return this.minute;}

    public int getSecond() {return this.second;}

    public void setHour(int hour) {
        if (hour >= 0 && hour <= 23) {
            this.hour = hour;
        } else {
            System.out.println("不正な値");
        }
    }

    public void setMinute(int minute) {
        if (minute >= 0 && minute <= 60) {
            this.minute = minute;
        } else {
            System.out.println("不正な値");
        }
    }

    public void setSecond(int second) {
        if (second >= 0 && second <= 60) {
            this.second = second;
        } else {
            System.out.println("不正な値");
        }
    }

    public String getCurrentTime() {
        String res = String.format("現在の時間は%d:%d:%dです", this.hour, this.minute, this.second);
        return res;
    }
}
