//
// Created by 김종신 on 2020/02/14.
//
#include <bits/stdc++.h>

constexpr auto INF = 1e9 + 1;
using namespace std;
long long x, y, z, res = 0, s = 0, e = INF, mid;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> x >> y;
    z = 100 * y / x;
    if (z > 98) {
        cout << "-1\n";
        return 0;
    }
    while (s <= e) {
        mid = (s + e) / 2;
        100 * (y + mid) / (x + mid) > z ? e = mid - 1 : s = mid + 1;
    }
    cout << s << "\n";
    return 0;
}