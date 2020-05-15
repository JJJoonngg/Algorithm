//
// Created by 김종신 on 2020/05/15.
//
#include <bits/stdc++.h>

#define MAXI 101
#define ll long long
using namespace std;
ll arr[MAXI], N, i, j, dp[MAXI][21];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (i = 1; i <= N; i++) cin >> arr[i];
    dp[1][arr[1]] = 1;
    for (i = 2; i < N; i++) {
        for (j = 0; j <= 20; j++) {
            if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
            if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
        }
    }
    cout << dp[N - 1][arr[N]] << "\n";
    return 0;
}