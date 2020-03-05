//
// Created by 김종신 on 2020/03/04.
//
#include <bits/stdc++.h>

#define MAXI 17

using namespace std;
struct xyd {
    int x, y, d;
};
int arr[MAXI][MAXI], N, res = 0;
int dx[3][3] = {{0, 1, 0},
                {1, 1, 0},
                {0, 1, 1}};
int dy[3][3] = {{1, 1, 0},
                {0, 1, 0},
                {1, 0, 1}};


bool checkRange(int x, int y) { return 0 < x && x <= N && 0 < y && y <= N; }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    queue<xyd> q;
    q.push({1, 2, 0});
    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            xyd cur = q.front();
            q.pop();
            if (cur.x == N && cur.y == N) {
                res++;
                continue;
            }
            if (cur.d == 2) {
                for (int i = 0; i < 3; i++) {
                    int nx = cur.x + dx[cur.d][i];
                    int ny = cur.y + dy[cur.d][i];
                    if (!checkRange(nx, ny)) continue;
                    if (arr[nx][ny] == 1) continue;
                    if (i == 2 && (arr[cur.x + 1][cur.y] || arr[cur.x][cur.y + 1])) continue;
                    q.push({nx, ny, i});
                }
            } else {
                for (int i = 0; i < 2; i++) {
                    int nx = cur.x + dx[cur.d][i];
                    int ny = cur.y + dy[cur.d][i];
                    if (!checkRange(nx, ny)) continue;
                    if (arr[nx][ny] == 1) continue;
                    if (i == 1 && (arr[cur.x + 1][cur.y] || arr[cur.x][cur.y + 1])) continue;
                    int d = i == 1 ? 2 : cur.d;
                    q.push({nx, ny, d});
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}