//
// Created by 김종신 on 2020/02/28.
//
#include <bits/stdc++.h>

#define MAXI 51
using namespace std;
int N, M, r, c, d, nx, ny, nd, res = 1;
int arr[MAXI][MAXI];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int turn(int dir) {
    if (dir == 0) return 3;
    else if (dir == 1) return 0;
    else if (dir == 2) return 1;
    else if (dir == 3) return 2;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    arr[r][c] = -1;
    while (true) {
        int cur = d;
        bool flag = false;
        int cant = 0;
        for (int i = 0; i < 4; i++) {
            nd = turn(d);
            nx = r + dx[nd], ny = c + dy[nd];
            if (!arr[nx][ny]) {
                flag = true;
                break;
            } else if (arr[nx][ny] == 1 ||arr[nx][ny] == -1|| !checkRange(nx, ny)) {
                d = nd;
                cant++;
            }
        }
        if (flag) {
            arr[nx][ny] = -1;
            res++;
            d = nd;
        }
        if (cant == 4) {
            nx = r - dx[cur], ny = c - dy[cur], d = cur;
            if (!checkRange(nx, ny) || arr[nx][ny] == 1)
                break;
        }
        r = nx, c = ny;
    }
    cout << res << "\n";

    return 0;
}