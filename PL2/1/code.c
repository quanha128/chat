#include <stdio.h>

int f(int x) {
    return f(x-1);
}

int sigma(int n) {
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum+=i;
    }
    return sum;
}

int gcd (int a, int b) {
    int i = 1; int max=0;
    while (i <= a && i <= b) {
        if (a%i==0 && b%i==0) max = i;
        i++;
    }
    return max;
}

int main() {
    printf("%d\n", gcd(30, 48));
    return 0;
}