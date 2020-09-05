//
// Created by 김종신 on 2020/09/05.
//
#include <bits/stdc++.h>

using namespace std;
int A, B, m, input, tmp = 0;
vector<int> v, rv;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> A >> B >> m;
    while (m--) cin >> input, v.push_back(input);

    for (auto a : v) tmp *= A, tmp += a;
    while (tmp) rv.push_back(tmp % B), tmp /= B;
    reverse(rv.begin(), rv.end());

    for (auto a : rv) cout << a << " ";
    cout << "\n";
    return 0;
}