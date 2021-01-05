//
// Created by 김종신 on 21. 1. 5..
//
#include <bits/stdc++.h>

#define MAXI 100000 + 1
using namespace std;
int light[MAXI], n, m, res = MAXI, _s, _e;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> light[i];
    _s = 1, _e = n;
    while (_s <= _e) {
        int mid = (_s + _e) / 2;
        bool flag = true;
        if (light[0] - mid > 0 || light[m - 1] + mid < n) flag = false;
        for (int i = 1; i <= m - 2; i++) {
            if (light[i - 1] + mid < light[i] - mid) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res = min(res, mid);
            _e = mid - 1;
        } else {
            _s = mid + 1;
        }
    }
    cout << res << "\n";
    return 0;
}