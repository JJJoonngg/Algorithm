//
// Created by 김종신 on 20. 12. 2020
//
#include <bits/stdc++.h>

#define MAXI 1000+1
using namespace std;
int n, m, i, j, res = 0;
char arr[MAXI][MAXI];
int dp[MAXI][MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] == '1' ? 1 : 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (arr[i][j] == '1') {
                if (dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0 && dp[i][j - 1] != 0) {
                    if (dp[i - 1][j] != 1 && dp[i - 1][j - 1] != 1 && dp[i][j - 1] != 1) {
                        int siz = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
                        int temp = sqrt(siz) + 1;
                        dp[i][j] = pow(temp, 2);
                    } else {
                        dp[i][j] = 4;
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
    }

    cout << res << "\n";
    return 0;
}