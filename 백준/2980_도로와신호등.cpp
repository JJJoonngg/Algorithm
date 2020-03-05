//
// Created by 김종신 on 2020/02/20.
//
#include <bits/stdc++.h>

using namespace std;
int N, L, D, R, G, res = 0, cur = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> L;
    while (N--) {
        cin >> D >> R >> G;
        res += D - cur;
        cur = D;
        while (res % (R + G) < R) res++;
    }
    res += L - cur;
    cout << res << "\n";
    return 0;
}