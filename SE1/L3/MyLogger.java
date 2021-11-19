package L3;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class MyLogger {
    private String log;
    private int cnt;
    private static int instances;

    public MyLogger(String logfile) {
        if (instances<3) {
            this.log = logfile;
            instances++;
        }
        else throw new UnsupportedOperationException();
    }

    public void write(String str) {
        try {
            File newlog = new File(log);
            FileWriter writer = new FileWriter(newlog, true);
            writer.write(str+"\n\n");
            writer.close();
        } catch(IOException e) {
            System.out.println("write error");
        } finally {
            cnt++;
        }
    }

    public static void free() {
        if (instances > 0) instances--;
        else throw new Error();
    }

    public int count() {
        return cnt;
    }
}
