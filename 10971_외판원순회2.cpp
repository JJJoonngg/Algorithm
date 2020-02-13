//
// Created by 김종신 on 2020/02/14.
//
#include <bits/stdc++.h>

#define INF 1e9
#define MAXI 11
using namespace std;
int n, arr[MAXI][MAXI], res = INF;
bool visit[MAXI];

void dfs(int s, int next, int val, int cnt) {
    if (cnt == n && s == next) {
        res = min(res, val);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (arr[next][i] == 0) continue;
        if (!visit[i]) {
            visit[i] = true;
            if (val + arr[next][i] <= res)
                dfs(s, i, val + arr[next][i], cnt + 1);
            visit[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        dfs(i, i, 0, 0);


    cout << res << "\n";
    return 0;
}