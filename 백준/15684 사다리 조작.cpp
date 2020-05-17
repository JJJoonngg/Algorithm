//
// Created by 김종신 on 2020/05/17.
//
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;
int n, m, h, a, b, res = INF;
bool arr[31][11];

bool checkStatus() {
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        for (int j = 1; j <= h; j++) {
            if (arr[j][tmp]) tmp++;
            else if (arr[j][tmp - 1]) tmp--;
        }
        if (tmp != i) return false;
    }
    return true;
}

void backTracking(int cur, int cnt) {
    if (res <= cnt) return;
    if (checkStatus()) {
        res = cnt;
        return;
    }
    if (cnt == 3) return;
    for (int i = cur; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][j]) {
                j++;
                continue;
            }
            arr[i][j] = true;
            backTracking(i, cnt + 1);
            arr[i][j] = false;
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = true;
    }
    backTracking(1, 0);
    if (res > 3) res = -1;
    cout << res << "\n";
    return 0;
}