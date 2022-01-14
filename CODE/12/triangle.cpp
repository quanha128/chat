#include <bits/stdc++.h>
using namespace std;

#define area(a, b, c) a[0]*(b[1]-c[1]) + b[0]*(c[1]-a[1]) + c[0]*(a[1]-b[1])
// #define area(a, b, c) (b[0]-a[0])*(c[1]-a[1]) - (c[0]-a[0])*(b[1]-a[1])

int main() {
  int n; cin >> n;
  vector<vector<int>> v(n, vector<int>(2));
  for (int i=0; i<n; i++) {
    cin >> v[i][0] >> v[i][1];
  }
  int ans = 0;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      for (int k=j+1; k<n; k++) {
        if (area(v[i], v[j], v[k]) != 0)  ans++;
      }
    }
  }

  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<2; j++) {
  //     cout << v[i][j] << "\t";
  //   }
  //   cout << endl;
  // }
  cout << ans << endl;
}