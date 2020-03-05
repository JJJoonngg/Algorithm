//
// Created by 김종신 on 2019/12/31.
// Math Problem
//
#include <bits/stdc++.h>

using namespace std;
long long a, b, c, res;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    if (b >= c) res = -1;
    else res = a / (c - b) + 1;
    cout << res << "\n";
    return 0;
}