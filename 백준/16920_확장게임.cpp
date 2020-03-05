//
// Created by 김종신 on 2020/02/21.
//
#include <bits/stdc++.h>

#define MAXI 1001
using namespace std;
int N, M, P, S[10], res[10], cnt = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int visit[MAXI][MAXI];

bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

struct xy {
    int x, y;
};
char arr[MAXI][MAXI];
queue<xy> q[10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++) cin >> S[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.')cnt++;
            if ('1' <= arr[i][j] && arr[i][j] <= '9') {
                q[arr[i][j] - '0'].push({i, j});
                visit[i][j] = arr[i][j] - '0';
                res[arr[i][j] - '0']++;
            }
        }
    }
    while (true) {
        bool flag = false;
        for (int idx = 1; idx <= P; idx++)
            for (int j = 0; j < S[idx]; j++) {
                int siz = q[idx].size();
                if (siz == 0) break;
                for (int a = 0; a < siz; a++) {
                    xy cur = q[idx].front();
                    q[idx].pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = cur.x + dx[i];
                        int ny = cur.y + dy[i];
                        if (!checkRange(nx, ny) || visit[nx][ny] != 0) continue;
                        if (arr[nx][ny] == '.') {
                            visit[nx][ny] = idx;
                            res[idx]++;
                            q[idx].push({nx, ny});
                            cnt--;
                            flag = cnt == 0 ? false : true;
                        }
                    }
                }
            }
        if (!flag) break;
    }
    for (int i = 1; i <= P; i++)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}