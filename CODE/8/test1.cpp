#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(string year) {
    int byear;
    int offset = stoi(year.substr(1, year.size()));
    if (year.front() == 'M') {
        byear = 1868 + offset;
    } else if (year.front() == 'T') {
        byear = 1912 + offset;
    } else if (year.front() == 'S') {
        byear = 1926 + offset;
    } else if (year.front() == 'H') {
        byear = 1989 + offset;
    } else {
        byear = 2019 + offset;
    }

    cout << byear;

    if (byear % 4 ==0) {
        if (byear % 100 == 0) {
            if (byear % 400 ==0) {
                return 1;
            } else return 0;
        } else return 1;
    } else return 1;
}

int main() {
    cout << isLeapYear("H033");
    return 0;
}