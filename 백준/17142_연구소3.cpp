//
// Created by 김종신 on 2020/02/25.
//
#include <bits/stdc++.h>

#define MAXI 51
#define INF 1e9
using namespace std;
int N, M, arr[MAXI][MAXI], cnt[11][MAXI][MAXI], tmp, tmp2, res, totalCnt = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct xy {
    int x, y;
};
vector<xy> virus;
vector<int> v;
bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

void bfs(int idx) {
    queue<xy> q;
    q.push({virus[idx].x, virus[idx].y});
    cnt[idx][virus[idx].x][virus[idx].y] = 0;
    while (!q.empty()) {
        xy cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (!checkRange(nx, ny)) continue;
            if (cnt[idx][nx][ny] == -1 && arr[nx][ny] != 1) {
                cnt[idx][nx][ny] = cnt[idx][cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (cnt[idx][i][j] == -1)
                cnt[idx][i][j] = INF;
}

int backTracking(int idx) {
    int tmp, tmp2;
    if (v.size() == M) {
        tmp = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] != 0) continue;
                tmp2 = INF;
                for (int k = 0; k < v.size(); k++) {
                    tmp2 = min(tmp2, cnt[v[k]][i][j]);
                }
                tmp = max(tmp, tmp2);
            }
        }
        return tmp;
    }
    if (idx == virus.size()) return INF;
    tmp = INF;
    for (int i = idx; i < virus.size(); i++) {
        v.push_back(i);
        tmp = min(tmp, backTracking(i + 1));
        v.pop_back();
    }
    return tmp;

}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    memset(cnt, -1, sizeof(cnt));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({i, j});
            if (!arr[i][j]) totalCnt++;
        }
    }
    if (!totalCnt) {
        cout << "0\n";
        return 0;
    }
    memset(cnt, -1, sizeof(cnt));
    for (int i = 0; i < virus.size(); i++) bfs(i);

    int res = backTracking(0);
    if (res == INF) res = -1;
    cout << res << "\n";
    return 0;
}