#include <iostream>
using namespace std;

int main() {
    int X = 0;
    cin >> X;
    if (X==0) printf("No\n");
    else if (X%100!=0) printf("No\n");
    else printf("Yes\n");
}