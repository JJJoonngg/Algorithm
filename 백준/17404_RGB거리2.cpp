//
// Created by 김종신 on 2020/02/24.
//
#include <bits/stdc++.h>

#define INF 1e9
#define MAXI 1001
using namespace std;
int n, r, g, b, rgb[3][MAXI], dp[3][MAXI], res = INF;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        rgb[0][i] = r, rgb[1][i] = g, rgb[2][i] = b;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)dp[j][0] = rgb[j][0];
            else dp[j][0] = INF;
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + rgb[0][j];
            dp[1][j] = min(dp[0][j - 1], dp[2][j - 1]) + rgb[1][j];
            dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + rgb[2][j];
        }
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            res = min(res, dp[j][n - 1]);
        }
    }
    cout << res << "\n";


    return 0;
}