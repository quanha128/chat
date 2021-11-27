#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> sum;
  for (int i=0; i<n; i++) {
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    sum.push_back(s1+s2+s3);
  }

  vector<int> top = sum;
  sort(begin(top), end(top), greater<>());
  int top_k = top[k-1];

  for (int i=0; i<sum.size(); i++) {
    if (sum[i] + 300 >= top_k) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }

  // for (int i=0; i<top.size(); i++) {
  //   cout << top[i] << "\n";
  // }
}
