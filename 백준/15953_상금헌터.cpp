//
// Created by 김종신 on 2020/02/26.
//
#include <bits/stdc++.h>

using namespace std;
int t, a, b;

int cal1(int a) {
    if (a == 1) return 5000000;
    else if (2 <= a && a <= 3) return 3000000;
    else if (4 <= a && a <= 6) return 2000000;
    else if (7 <= a && a <= 10) return 500000;
    else if (11 <= a && a <= 15) return 300000;
    else if (16 <= a && a <= 21) return 100000;
    else return 0;
}

int cal2(int b) {
    if (b == 1) return 5120000;
    else if (2 <= b && b <= 3) return 2560000;
    else if (4 <= b && b <= 7) return 1280000;
    else if (8 <= b && b <= 15) return 640000;
    else if (16 <= b && b <= 31) return 320000;
    else return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << cal1(a) + cal2(b) << "\n";
    }
    return 0;
}