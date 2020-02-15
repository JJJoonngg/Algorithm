//
// Created by 김종신 on 2020/02/16.
//
#include <bits/stdc++.h>

using namespace std;
int n, m, input, res;
bool arr[10];

bool checkPossible(int x) {
    if (x == 0) return !arr[0];
    while (x) {
        if (arr[x % 10]) return false;
        x /= 10;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        arr[input] = true;
    }

    res = abs(n - 100);
    int maxi = (n * 2 - 100) > 100 ? (n * 2 - 100) : 100;

    for (int i = 0; i <= maxi; i++) {
        int cnt = to_string(i).length() + abs(n - i);
        if (checkPossible(i)) res = min(cnt, res);
    }
    cout << res <<"\n";
    return 0;
}