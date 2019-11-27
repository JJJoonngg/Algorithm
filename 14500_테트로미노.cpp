//
// Created by 김종신 on 2019/11/25.
//
#include <bits/stdc++.h>

#define MAXI 501
using namespace std;

int arr[MAXI][MAXI];
bool visit[MAXI][MAXI];
int n, m;
int res = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool checkRange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int dfs(int x, int y, int cnt) {
    if (cnt >=5 ) return 0;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!checkRange(nx, ny))continue;
        if(visit[nx][ny])continue;
        visit[nx][ny] = true;
        ans = max(ans, dfs(nx, ny, cnt + 1) + arr[x][y]);
        visit[nx][ny] = false;
    }
    return ans;
}

int expt(int x, int y) {
    int ans = 0;
    if (x > 0 && y > 0 && y < m - 1) ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1]);
    if (x < n - 1 && y > 0 && y < m - 1) ans = max(ans, arr[x][y] + arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1]);
    if (x < n - 1 && x > 0 && y < m - 1) ans = max(ans, arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y + 1]);
    if (x < n - 1 && x > 0 && y > 0) ans = max(ans, arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y - 1]);

    return ans;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = true;
            res = max(dfs(i, j, 1), res);
            res = max(expt(i, j), res);
            visit[i][j] = false;
        }
    }
    cout << res << "\n";
    return 0;
}

