//
// Created by 김종신 on 2020/03/06.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    while (b > 0) {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}


ll T, A, B;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << lcm(A, B) << "\n";
    }
    return 0;
}