//
// Created by 김종신 on 2020/01/30.
//
#include <bits/stdc++.h>

#define MAXI 1000 + 1
using namespace std;

int t, n, X1, X2, Y1, Y2, CX, CY, r, res = 0, dist;
bool flag1, flag2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> X1 >> Y1 >> X2 >> Y2 >> n;
        res = 0;
        while (n--) {
            flag1 = flag2 = false;
            cin >> CX >> CY >> r;
            r *= r;
            dist = pow(CX - X1, 2) + pow(CY - Y1, 2);
            if (dist < r) flag1 = true;
            dist = pow(CX - X2, 2) + pow(CY - Y2, 2);
            if (dist < r) flag2 = true;
            if (flag1 != flag2) res++;
        }
        cout << res << "\n";
    }
    return 0;
}