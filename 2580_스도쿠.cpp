//
// Created by 김종신 on 2020/01/03.
//  BackTracking
//

#include <bits/stdc++.h>

#define MAXI 10
using namespace std;
struct xy {
    int x, y;
};
vector<xy> square;
int arr[MAXI][MAXI];

bool checkCol(int col, int num) {
    for (int row = 0; row < 9; row++)
        if (arr[row][col] == num)
            return false;
    return true;
}

bool checkRow(int row, int num) {
    for (int col = 0; col < 9; col++)
        if (arr[row][col] == num)
            return false;
    return true;
}

bool checkSquare(int row, int col, int num) {
    row /= 3;
    row *= 3;
    col /= 3;
    col *= 3;
    for (int i = row; i < row + 3; i++)
        for (int j = col; j < col + 3; j++)
            if (arr[i][j] == num)
                return false;
    return true;
}

void dfs(int cnt) {
    if (cnt == square.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    for (int cur = 1; cur <= 9; cur++) {
        int row = square[cnt].x;
        int col = square[cnt].y;
        if (!checkCol(col, cur)) continue;
        if (!checkRow(row, cur)) continue;
        if (!checkSquare(row, col, cur))continue;
        arr[row][col] = cur;
        dfs(cnt + 1);
        arr[row][col] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int startX, startY;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                square.push_back({i, j});
            }
        }
    }
    for (int cur = 1; cur <= 9; cur++) {
        int row = square[0].x;
        int col = square[0].y;
        if (!checkCol(col, cur)) continue;
        if (!checkRow(row, cur)) continue;
        if (!checkSquare(row, col, cur))continue;
        arr[row][col] = cur;
        dfs(1);
        arr[row][col] = 0;
    }
    return 0;
}