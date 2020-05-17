//
// Created by 김종신 on 2020/05/17.
//
#include <bits/stdc++.h>

#define MAXI 101
using namespace std;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
int N, x, y, d, g, res = 0, arr[MAXI][MAXI];
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> y >> x >> d >> g;
        v.clear();
        int nx = x + dx[d], ny = y + dy[d];
        arr[x][y] = arr[nx][ny] = 1, v.push_back(d);
        while (g--) {
            int siz = v.size();
            for (int j = siz - 1; j > -1; j--) {
                int nd = (v[j] + 1) % 4;
                nx += dx[nd], ny += dy[nd];
                arr[nx][ny] = 1;
                v.push_back(nd);
            }
        }
    }
    for (int i = 0; i < MAXI; i++)
        for (int j = 0; j < MAXI; j++)
            if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1)
                res++;
    cout << res << "\n";
    return 0;
}