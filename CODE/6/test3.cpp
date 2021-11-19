#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int s[N];
    int v[N];
    double t[N];
    for (int _=0; _<N; _++){
        int A;
        int B;
        cin >> A;
        cin >> B;
        s[_] = A;
        v[_] = B;
        t[_] = double(A)/double(B);
    }
    // left hand cursor
    int start = 0;
    // right hand cursor
    int end = N-1;
    // flag previous finished fuse
    // 0 for left, 1 for right
    int prev = -1;
    while (start != end) {
        if (t[start] > t[end]) {
            t[start] -= t[end];
            t[end] = 0;
            end --;
            prev = 1;
        } else if (t[start] < t[end]) {
            t[end] -= t[start];
            t[start] = 0;
            start ++;
            prev = 0;
        } else {
            if (start+1 == end) t[start] = -1;
            t[end] = 0;
            end--;
        }
    }

    double dist=0;

    for (int i=0; i<N; i++) {
        if (t[i]==0)
            dist += s[i];
        else if (t[i] == -1) {
            dist += s[i];
            break;
        } else {
            if (!prev) {
                dist += v[i] * t[i]/2;
                break;
            } else {
                double orit = double(s[i]) / double(v[i]);
                dist += v[i] * (orit-t[i]/2);
                break;
            }
        }
    }
    printf("%0.8lf\n", dist);
}