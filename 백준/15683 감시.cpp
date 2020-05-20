//
// Created by 김종신 on 2020/05/20.
//
#include <bits/stdc++.h>

using namespace std;
struct info {
    int x, y, cctv;
};
int n, m, res = 65, siz = 0, arr[9][9];
vector<info> v;

void rotation(int x, int y, int dir) {
    if (dir == 0) {
        for (int i = y - 1; i >= 0; i--) {
            if (arr[i][x] == 6) break;
            if (arr[i][x] == 0) arr[i][x]--;
        }
    } else if (dir == 1) {
        for (int i = x + 1; i < m; i++) {
            if (arr[y][i] == 6) break;
            if (arr[y][i] == 0) arr[y][i]--;
        }
    } else if (dir == 2) {
        for (int i = y + 1; i < n; i++) {
            if (arr[i][x] == 6) break;
            if (arr[i][x] == 0) arr[i][x]--;
        }
    } else if (dir == 3) {
        for (int i = x - 1; i >= 0; i--) {
            if (arr[y][i] == 6) break;
            if (arr[y][i] == 0) arr[y][i]--;
        }
    }
}

void DFS(int cnt) {
    if (cnt == siz) {
        int tmp = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (arr[i][j] == 0) tmp++;
        res = min(res, tmp);
        return;
    }
    int tmp[9][9];
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) tmp[i][j] = arr[i][j];

    for (int k = 0; k < 4; k++) {
        rotation(v[cnt].x, v[cnt].y, k);
        if (v[cnt].cctv == 2) rotation(v[cnt].x, v[cnt].y, k + 2);
        else if (v[cnt].cctv == 3) rotation(v[cnt].x, v[cnt].y, (k + 1) % 4);
        else if (v[cnt].cctv == 4) rotation(v[cnt].x, v[cnt].y, (k + 1) % 4), rotation(v[cnt].x, v[cnt].y, (k + 2) % 4);
        else if (v[cnt].cctv == 5) continue;
        DFS(cnt + 1);
        for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) arr[i][j] = tmp[i][j];
    }
    if (v[cnt].cctv == 5) DFS(cnt + 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6)
                v.push_back({j, i, arr[i][j]});
        }
    }
    siz = v.size();
    DFS(0);
    cout << res << "\n";
    return 0;
}