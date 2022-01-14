#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c; cin >> a >> b >> c;

  // if c even
  if (c % 2 == 0) {
    if (a < 0) a = abs(a);
    if (b < 0) b = abs(b);
    if (a == b) {
      cout << "=\n";
      return 0;
    }
    cout << (a>b? ">\n" : "<\n");
    return 0;
  } //if c odd
  else if (c % 2==1) {
    if (a == b) {
      cout << "=\n";
      return 0;
    }
    cout << (a>b? ">\n" : "<\n");
    return 0;
  }
}