//
// Created by 김종신 on 2020/05/21.
//
#include <bits/stdc++.h>

#define MAXI 51
using namespace std;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int n, m, arr[MAXI][MAXI], res = -1;
int cnt[MAXI][MAXI];
struct info {
    int x, y;
};
vector<info> land;

bool checkRange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int bfs(info a) {
    memset(cnt, 0, sizeof(cnt));
    queue<info> q;
    q.push(a);
    cnt[a.x][a.y] = 1;
    int tmp = 0;
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (!checkRange(nx, ny)) continue;
            if (arr[nx][ny] && cnt[nx][ny] == 0) {
                cnt[nx][ny] = cnt[cur.x][cur.y] + 1;
                tmp = max(tmp, cnt[nx][ny]);
                q.push({nx, ny});
            }
        }
    }
    return --tmp;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == 'W') arr[i][j] = 0;
            else arr[i][j] = 1, land.push_back({i, j});
        }
    }
    for (auto a : land)
        res = max(res, bfs(a));

    cout << res << "\n";
    return 0;
}