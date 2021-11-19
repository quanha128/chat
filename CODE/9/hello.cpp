#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=1;
    while (cin >> n, n>0)
    {
        int max = 0;
        int in;
        for (int i=0; i<n; i++) {
            if (cin >> in, in>max) max = in;
        }
        cout << max << "\n";
    }
    return 0;
}