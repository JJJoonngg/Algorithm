//
// Created by 김종신 on 2019/11/24.
//

#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
int N, res = INF;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int cur = 1; cur <= N; cur++) {
        int tmp = cur;
        int sum = cur;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N) {
            res = cur;
            break;
        }
    }
    if (res == INF) res = 0;
    cout << res << "\n";
    return 0;
}