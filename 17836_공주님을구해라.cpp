//
// Created by 김종신 on 2020/02/24.
//
#include <bits/stdc++.h>

#define INF 1e9
#define MAXI 101
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M, T, arr[MAXI][MAXI];
int cnt[MAXI][MAXI];
struct xy {
    int x, y;
};

bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int bfs(int ex, int ey) {
    memset(cnt, 0, sizeof(cnt));
    queue<xy> q;
    q.push({0, 0});
    int res = INF;
    while (!q.empty()) {
        xy cur = q.front();
        q.pop();
        if (cur.x == ex && cur.y == ey) {
            res = cnt[ex][ey];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx == 0 && ny == 0) continue;
            if (!checkRange(nx, ny)) continue;
            if (!cnt[nx][ny] && arr[nx][ny] != 1) {
                cnt[nx][ny] = cnt[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return res;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M >> T;
    xy s;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) s.x = i, s.y = j;
        }
    int res = min(bfs(N - 1, M - 1), bfs(s.x, s.y) + N - s.x + M - s.y - 2);
    res <= T ? cout << res << "\n" : cout << "Fail\n";
    return 0;
}