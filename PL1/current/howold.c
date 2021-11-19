#include <stdio.h>

int main() {
    FILE* fp = fopen("/proc/uptime", "r");
    float time;
    fscanf(fp, "%f", &time);
    int hour = time / 3600;
    int minute = time/60 - hour*60;
    float second = time - minute*60 - hour*3600;
    printf("%d hour(s) %d minute(s) %f second(s)\n", hour, minute, second);
    return 0;
}