#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int A, B;
    int res = 1;
    cin >> A;
    cin >> B;
    for (int i=0; i<(A-B); i++) {
        res *= 32;
    }
    cout << res;
    // vector<int> a;
    return 0;
}