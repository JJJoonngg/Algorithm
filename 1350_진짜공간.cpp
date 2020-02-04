//
// Created by 김종신 on 2020/02/04.
//
#include <bits/stdc++.h>

#define MAXI 1001
using namespace std;
long long res = 0, cluster, cnt = 0, N, arr[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> cluster;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) continue;
        int tmp = arr[i] / cluster;
        if (arr[i] % cluster != 0) tmp++;
        cnt += tmp;
    }
    res = cluster * cnt;
    cout << res << "\n";
    return 0;
}