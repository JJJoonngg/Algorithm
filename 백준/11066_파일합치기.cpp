//
// Created by 김종신 on 21. 3. 4..
//
#include <bits/stdc++.h>

#define INF 2e9
#define MAXI 502

using namespace std;

int cost[MAXI], sum[MAXI], dp[MAXI][MAXI];
int t, k;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }

        for (int i = 1; i < k; i++) {
            for (int j = 1; i + j <= k; j++) {
                int x = i + j;
                dp[j][x] = INF;

                for (int mid = j; mid < x; mid++) {
                    int _value = dp[j][mid] + dp[mid + 1][x] + sum[x] - sum[j - 1];
                    dp[j][x] = min(dp[j][x], _value);
                }
            }

        }

        cout << dp[1][k] << "\n";
    }
    return 0;
}