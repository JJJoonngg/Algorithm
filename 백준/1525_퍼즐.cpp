//
// Created by 김종신 on 2020/03/09.
//
#include <bits/stdc++.h>

using namespace std;
int arr[3][3], res[3][3], idx = 1;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool checkRange(int x, int y) { return 0 <= x && x < 3 && 0 <= y && y < 3; }

bool checkRes() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i][j] != res[i][j])
                return false;
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            res[i][j] = idx++;
        }
    res[2][2] = 0;

    return 0;
}