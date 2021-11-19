// K-normal
int foo (int n) {
    int t1, t2, t3, t4;
    t1 = 0;
    t4 = n;
    while (t4>0) {
        t2 = t4 % 2;
        t3 = t4 * t4;
        if (t2 == 0) {
            t1 = t1 + t3;
        }
        else {
            t1 = t1 - t3;
        }
        t4 = t4 - 1;
    }
    return t1;
}

// SSA
int foo (int n0) {
    int n1, n2, sum1, sum2, sum3, sum4, t1, t2, t3, t4;
    int sum0 = 0;
    while (n2 = phi(n0,n1), sum4 = phi(sum0, sum3), n2>0) {
        t1 = n2 % 2;
        t2 = n2 * n2;
        if (t1 == 0) {
            t3 = sum2 + t2;
            sum1 = t3;
        } else {
            t4 = sum2 - t2;
            sum2 = t4;
        }
        sum3 = phi(sum1, sum2);
        n1 = n0 - 1;
    }
    return sum4;
}