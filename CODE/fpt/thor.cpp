#include<bits/stdc++.h>
using namespace std;

bool thornPrime(int n) {
  if (n<=1) return false;
  if (n==2) return false;
  if (n==3) return true;
  if (n%2==0 || n%3==0) return false;
  int i = 5;
  while (i*i<=n) {
    if (n%i==0 || n%(i+2)==0) {
      return false;
    }
    i = i+6;
  }
  int dum = n;
  while(dum>0) {
    int digit = dum%10;
    if (digit%2==0) {
      return false;
    }
    dum /= 10;
  }
  return true;
}

int main() {
  cout << (thornPrime(131)?"true":"false");
}