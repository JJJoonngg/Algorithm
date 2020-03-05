//
// Created by 김종신 on 2020/02/14.
//
#include <bits/stdc++.h>

using namespace std;
string a, b, res = "";
int cur = 0, up = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.length() != b.length()) {
        a.length() > b.length() ? b += '0' : a += '0';
    }

    for (int i = 0; i < a.length(); i++) {
        cur = (a[i] - '0' + b[i] - '0' + up) % 10;
        res += to_string(cur);
        up = (a[i] - '0' + b[i] - '0' + up) / 10;
    }
    if (up != 0) res += to_string(up);

    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}