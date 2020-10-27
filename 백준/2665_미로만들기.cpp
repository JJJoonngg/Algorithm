//
// Created by 김종신 on 2020/10/27.
//
#include <bits/stdc++.h>

#define MAXI 51
#define INF 1e9

using namespace std;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int arr[MAXI][MAXI], res[MAXI][MAXI], n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        for (int j = 0; j < input.length(); j++) arr[i][j] = input[j] - '0';
    }
    for (int i = 0; i < MAXI; i++)for (int j = 0; j < MAXI; j++) res[i][j] = INF;
    res[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny]) {
                if (res[nx][ny] > res[cur.first][cur.second]) {
                    res[nx][ny] = res[cur.first][cur.second];
                    q.push({nx, ny});
                }
            } else {
                if (res[nx][ny] > res[cur.first][cur.second] + 1) {
                    res[nx][ny] = res[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << res[n - 1][n - 1] << "\n";
    return 0;
}