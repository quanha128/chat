#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n, n>0) {
        bool first=false, second=false, third=false, fourth=false, fifth=false;
        vector<string> v(n);
        for (int i=0; i<n; i++) {
            string dummy;
            cin >> dummy;
            v[i] = dummy;
        }
        int index = 0;
        while(!(first|second|third|fourth|fifth)) {
            if (!first) {
                int sum1=0;
                int cnt = 0;
                while(sum1<5) {
                    sum1 += v[index].length();
                    index ++;
                    cnt ++;
                }
                if (sum1 > 5) {
                    index -= cnt;
                    cnt = 0;
                    continue;
                }
            }
        }
    }
}