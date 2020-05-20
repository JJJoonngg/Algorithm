#include <bits/stdc++.h>

#define MAXI 101
#define INF 987654321
using namespace std;
int n, res = INF, arr[MAXI][MAXI];
bool visit[MAXI][MAXI];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
struct info {
    int x, y;
};
vector<info> land;

bool checkRange(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

int bfs(int num) {
    int tmp = 0;
    queue<info> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (arr[i][j] == num) visit[i][j] = true, q.push({i, j});

    while (!q.empty()) {
        int siz = q.size();
        for (int k = 0; k < siz; k++) {
            info cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (!checkRange(nx, ny)) continue;
                if (arr[nx][ny] != 0 && arr[nx][ny] != num) return tmp;
                if (arr[nx][ny] == 0 && !visit[nx][ny]) visit[nx][ny] = true, q.push({nx, ny});
            }
        }
        tmp++;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)arr[i][j] = -1, land.push_back({i, j});
        }
    }
    int num = 1;
    for (auto a : land) {
        if (!visit[a.x][a.y]) {
            queue<info> q;
            q.push(a);
            visit[a.x][a.y] = true, arr[a.x][a.y] = num;
            while (!q.empty()) {
                info cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i], ny = cur.y + dy[i];
                    if (!checkRange(nx, ny)) continue;
                    if (!visit[nx][ny] && arr[nx][ny] == -1) visit[nx][ny] = true, arr[nx][ny] = num, q.push({nx, ny});
                }
            }
            num++;
        }
    }

    for (int i = 1; i < num; i++) {
        res = min(res, bfs(i));
        memset(visit, false, sizeof(visit));
    }
    cout << res << "\n";
    return 0;
}