#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> rotate_ccw(vector<vector<string>> orig, int n) {
    vector<vector<string>> res(n, vector<string>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            res[i][j] = orig[j][i];
        }
    }
    return res;
}



int main() {
    int n;
    cin >> n;

    vector<vector<string>> s(n, vector<string>(n));
    vector<vector<string>> t(n, vector<string>(n));

    for (int i=0; i<n; i++) {
        string row;
        cin >> row;
        for (int j=0; j<n; j++) {
            s[i][j] = row[j];
        }
    }
    for (int i=0; i<n; i++) {
        string row;
        cin >> row;
        for (int j=0; j<n; j++) {
            t[i][j] = row[j];
        }
    }

    vector<vector<string>> res = rotate_ccw(s, n);
    // test
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }
}