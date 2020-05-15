//
// Created by 김종신 on 2020/05/15.
//
#include <bits/stdc++.h>

#define MAXI 1001
using namespace std;
struct info {
    int x, y, penetration, cnt;
};
int arr[MAXI][MAXI], N, M, K, i, j;
bool visit[MAXI][MAXI][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int bfs() {
    queue<info> q;
    q.push({0, 0, 0, 1});
    visit[0][0][0] = true;
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.x == N - 1 && cur.y == M - 1)
            return cur.cnt;
        for (i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (!checkRange(nx, ny)) continue;
            if (visit[nx][ny][cur.penetration]) continue;
            if (!arr[nx][ny]) {
                visit[nx][ny][cur.penetration] = true;
                q.push({nx, ny, cur.penetration, cur.cnt + 1});
            } else if (arr[nx][ny] && cur.penetration < K) {
                visit[nx][ny][cur.penetration + 1] = true;
                q.push({nx, ny, cur.penetration + 1, cur.cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%1d", &arr[i][j]);
    printf("%d\n", bfs());
    return 0;
}