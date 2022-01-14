#include<bits/stdc++.h>
using namespace std;

bool roundSquare(int n) {
  int sum = 0;

  for (int i=0; i*i<=n; i++) {
    if(i*i == n) break;
  }

  while (n>0) {
    int digit = n%10;
    sum += digit;
    n/=10;
  }
  if (sum!=10) return false;

  return true;
}

int main() {
  cout << (roundSquare(361)?"true":"false");
}