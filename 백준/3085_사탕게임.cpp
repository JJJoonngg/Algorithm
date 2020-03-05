//
// Created by 김종신 on 2019/12/26.
// Bruth Force Problem
//

#include <bits/stdc++.h>

#define MAXI 50 + 1
using namespace std;

char arr[MAXI][MAXI];
int n, res = 0;

void func() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] == arr[i][j + 1])
                cnt++;
            else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
    }
    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j][i] == arr[j + 1][i])
                cnt++;
            else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                swap(arr[i][j], arr[i][j + 1]);
                func();
                swap(arr[i][j], arr[i][j + 1]);
            }
            if (i + 1 < n) {
                swap(arr[i][j], arr[i + 1][j]);
                func();
                swap(arr[i][j], arr[i + 1][j]);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}