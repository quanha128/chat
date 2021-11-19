#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    string res = "";
    if (n==1) {
        cout << "A" << "\n";
        return 0;
    }
    while(n > 0) {
        cout << n << " -> ";
        if (n%2 != 0) {
            n -= 1;
            res += "A";
        }
        cout << n << " -> ";
        n /= 2;
        res += "B";
        cout << n << "\n";
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}