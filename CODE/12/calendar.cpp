#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  // vector<vector<int>> v(n, vector<int>(m));
  int v[n][m];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> v[i][j];
    }
  }

  int idx = v[0][0] + m - 7; // prepare for the first iteration of n
  for (int i=0; i<n; i++) {
    idx = idx - m + 7;
    for (int j=0; j<m; j++) {
      if(j!=m-1 && v[i][j]%7==0) {
        cout << "No" << endl;
        return 0;
      }
      if(v[i][j] != idx) {
        cout << "No" << endl;
        return 0;
      }
      idx ++;
    }
  }

  cout << "Yes" << endl;
  
}