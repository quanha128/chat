#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;

  // 0 = white, 1 = black
  // vector<vector<int>> grid(n, vector<int>(n), 0);
  int grid[n][n];
  fill(*grid, *grid+n*n, 0);

  // operation 1
  for (ll k=max(1-a, 1-b); k<=min(n-a, n-b); k++) {
    grid[a+k][b+k] = 1;
  }

  // operation 2
  for (ll k=max(1-a, b-n); k<=min(n-a, b-1); k++) {
    grid[a+k][b-k] = 1;
  }

  for (ll i=p; i<= q; i++) {
    for (ll j=r; j<=s; j++) {
      if (grid[i][j] == 1) cout << "#";
      else cout << ".";
    }
    cout << "\n";
  }
}