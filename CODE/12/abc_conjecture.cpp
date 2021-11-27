#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans =0;
  for (long long a=1; a<n+1; a++) {
    if (a*a*a > n) break;
    for (long long b=a; b<n+1; b++) {
      if(a*b*b>n) break;
      ans += n/a/b-b+1;
    }
  }
  cout << ans;
}