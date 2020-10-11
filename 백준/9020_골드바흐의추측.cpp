//
// Created by 김종신 on 2020/10/11.
//
#include <bits/stdc++.h>

#define MAXI 10001
using namespace std;
int t, n, res;
bool prime[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    for (int i = 2; i * i < MAXI; i++) for (int j = i * i; j < MAXI; j += i) prime[j] = true;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = n / 2; i < n; i++) {
            if (!prime[i] && !prime[n - i]) {
                res = i;
                break;
            }
        }

        cout << n - res << " " << res << "\n";
    }
    return 0;
}