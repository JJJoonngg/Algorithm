//
// Created by 김종신 on 2020/02/21.
//
#include <bits/stdc++.h>

using namespace std;
long long res, n, k, q, x, y;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> k >> q;
    while (q--) {
        res = 0;
        cin >> x >> y;
        if (k == 1) {
            cout << abs(x - y) << "\n";
            continue;
        }
        while (x != y) {
            x < y ? y = (y - 2) / k + 1 : x = (x - 2) / k + 1;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}