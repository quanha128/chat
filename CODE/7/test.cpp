#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(26);
    for (int i=0; i<26; i++) {
        int P;
        cin >> P;
        v[i] = P;
    }
    for (int i=0; i<26; i++) {
        printf("%c", v[i]+96);
    }
    cout << "\n";
    return 0;
}