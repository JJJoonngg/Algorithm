//
// Created by 김종신 on 2020/02/29.
//
#include <bits/stdc++.h>

#define INF 2e9
#define MAXI 101
using namespace std;
int N, arr[MAXI], op[4], MAX = -INF, MIN = INF;

void dfs(int cnt, int res, int p, int m, int mu, int d) {
    if (cnt == N - 1) {
        MAX = max(res, MAX);
        MIN = min(res, MIN);
        return;
    }
    if (p > 0) dfs(cnt + 1, res + arr[cnt + 1], p - 1, m, mu, d);
    if (m > 0) dfs(cnt + 1, res - arr[cnt + 1], p, m - 1, mu, d);
    if (mu > 0) dfs(cnt + 1, res * arr[cnt + 1], p, m, mu - 1, d);
    if (d > 0) dfs(cnt + 1, res / arr[cnt + 1], p, m, mu, d - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    dfs(0, arr[0], op[0], op[1], op[2], op[3]);
    cout << MAX << "\n" << MIN << "\n";
    return 0;
}