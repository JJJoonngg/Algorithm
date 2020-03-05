//
// Created by 김종신 on 2020/01/27.
//
#include <bits/stdc++.h>

#define MAXI 51
#define INF 1e9
using namespace std;
int arr[MAXI][MAXI], N, res = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char input;
            cin >> input;
            if (input == 'Y') arr[i][j] = 1;
            else arr[i][j] = INF;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == j || j == k || i == k) continue;
                else if (arr[j][k] > arr[j][i] + arr[i][k])
                    arr[j][k] = arr[j][i] + arr[i][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            else if (arr[i][j] <= 2)
                tmp++;
        }
        res = max(tmp, res);
    }
    cout << res << "\n";
    return 0;
}
