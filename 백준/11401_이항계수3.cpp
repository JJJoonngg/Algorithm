//
// Created by 김종신 on 2020/10/11.
//
#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define MAXI 4000001
using namespace std;
ll fac[MAXI], n, k, tmp, _prev, _next, res;

void euclid(ll p, ll B) {
    if (p % B) {
        euclid(B, p % B);
        tmp = _next;
        _next = _prev - (p / B) * _next;
        _prev = tmp;
    } else {
        _prev = 0, _next = 1;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    fac[0] = fac[1] = 1;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) fac[i] = (fac[i - 1] * i) % mod;
    tmp = (fac[k] * fac[n - k]) % mod;
    euclid(mod, tmp);
    res = ((fac[n] % mod) * (_next % mod)) % mod;
    if (res < 0) res += mod;
    cout << res << "\n";
    return 0;
}