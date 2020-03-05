//
// Created by 김종신 on 2020/01/03.
// BackTracking
//
#include <bits/stdc++.h>

#define MAXI 11
using namespace std;
int arr[MAXI][MAXI], Left[MAXI * 2], Right[MAXI * 2];
int n, cur = 0, res[2];

void dfs(int row, int col, int color, int cnt) {
    if (row >= n) {
        res[color] = max(cnt, res[color]);
        return;
    }
    if (col >= n) {
        row++;
        col = col % 2 ? 0 : 1;
    }
    int tmp = col - row + n - 1;
    if (arr[row][col] && !Left[tmp] && !Right[col + row]) {
        Left[tmp] = Right[row + col] = 1;
        dfs(row, col + 2, color, cnt + 1);
        Left[tmp] = Right[row + col] = 0;
    }
    dfs(row, col + 2, color, cnt);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    dfs(0, 0, 0, 0);
    dfs(0, 1, 1, 0);

    cout << res[0] + res[1] << "\n";
    return 0;
}