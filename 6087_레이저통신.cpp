//
// Created by 김종신 on 2020/02/20.
//
#include <bits/stdc++.h>

#define INF 1e9
#define MAXI 101
using namespace std;
int W, H;
char arr[MAXI][MAXI];
int res[MAXI][MAXI];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
struct xy {
    int x, y, cnt, before;
};
vector<xy> c;

bool checkRange(int x, int y) { return 0 <= x && x < H && 0 <= y && y < W; }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C')
                c.push_back({i, j});
            res[i][j] = INF;
        }
    }
    queue<xy> q;
    for (int i = 0; i < 4; i++)q.push({c[0].x, c[0].y, 0, i});
    res[c[0].x][c[0].y] = 0;
    while (!q.empty()) {
        xy cur = q.front();
        res[cur.x][cur.y] = cur.cnt;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int ncnt = cur.before == i ? cur.cnt : cur.cnt + 1;
            if (!checkRange(nx, ny))continue;
            if (arr[nx][ny] == '*') continue;
            if (res[nx][ny] >= ncnt) {
                res[nx][ny] = ncnt;
                q.push({nx, ny, ncnt, i});
            }
        }
    }

    cout << res[c[1].x][c[1].y] << "\n";
    return 0;
}