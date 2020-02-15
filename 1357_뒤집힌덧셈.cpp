//
// Created by 김종신 on 2020/02/15.
//
#include <bits/stdc++.h>

using namespace std;
string x, y, z;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    z = to_string(stoi(x) + stoi(y));
    reverse(z.begin(), z.end());
    cout << stoi(z) << "\n";
    return 0;
}