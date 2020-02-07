//
// Created by 김종신 on 2020/02/06.
//
//https://www.acmicpc.net/problem/16234
#include <bits/stdc++.h>

#define MAXI 51
using namespace std;

int N, L, R, res = 0, cnt = 0, currentValue = 0;
int arr[MAXI][MAXI];
bool visit[MAXI][MAXI];
struct info {
    int x, y;
};
vector<info> v;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

bool checkRange(info tmp) { return 0 <= tmp.x && tmp.x < N && 0 <= tmp.y && tmp.y < N; }

void dfs(info cur) {
    for (int i = 0; i < 4; i++) {
        info tmp;
        tmp.x = cur.x + dx[i];
        tmp.y = cur.y + dy[i];
        if (!checkRange(tmp) || visit[tmp.x][tmp.y]) continue;
        int val = abs(arr[tmp.x][tmp.y] - arr[cur.x][cur.y]);
        if (L <= val && val <= R) {
            visit[tmp.x][tmp.y] = true;
            v.push_back(tmp);
            currentValue += arr[tmp.x][tmp.y];
            cnt++;
            dfs(tmp);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    while (true) {
        memset(visit, false, sizeof(visit));
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j])continue;
                v.clear();
                visit[i][j] = true;
                v.push_back({i, j});
                currentValue = arr[i][j];
                cnt = 1;
                info cur;
                cur.x = i, cur.y = j;
                dfs(cur);
                if (cnt >= 2) {
                    flag = true;
                    for (int i = 0; i < v.size(); i++)
                        arr[v[i].x][v[i].y] = currentValue / cnt;
                }
            }
        }
        if (flag) res++;
        else break;
    }
    cout << res << "\n";
    return 0;
}