//
// Created by 김종신 on 2020/02/28.
//
#include <bits/stdc++.h>

#define MAXI 101
using namespace std;
int N, L, arr[MAXI][MAXI], arr2[MAXI][MAXI];
bool check[MAXI][MAXI], flag;

int cal(int A[MAXI][MAXI]) {
    int res = 0;
    memset(check, false, sizeof(check));
    for (int i = 1; i <= N; i++) {
        flag = true;
        for (int j = 1; j < N; j++) {
            if (A[i][j] > A[i][j + 1]) {
                int tmp = j + L;
                if (tmp > N) {
                    flag = false;
                    break;
                }
                for (int k = j + 1; k <= tmp; k++) {
                    if (A[i][j] - A[i][k] != 1) {
                        flag = false;
                        break;
                    }
                    check[i][k] = true;
                }
                j += L - 1;
            }
        }
        if (!flag) continue;

        for (int j = N; j > 1; j--) {
            int tmp = j - L;
            if (A[i][j] > A[i][j - 1]) {
                if (tmp < 1) {
                    flag = false;
                    break;
                }

                for (int k = j - 1; k >= tmp; k--) {
                    if (check[i][k] || A[i][j] - A[i][k] != 1) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
                j -= L - 1;
            }
        }
        if (flag) res++;
    }
    return res;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr2[j][i] = arr[i][j];
        }
    cout << cal(arr) + cal(arr2) << "\n";
    return 0;
}