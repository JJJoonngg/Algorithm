//
// Created by 김종신 on 2019/11/24.
//

#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
int N;
int arr[12];
int cal[4]; // 0 : +, 1 : -, 2 : *, 3 : /
int MAX = INF * -1;
int MIN = INF;

void dfs(int cnt, int res, int plus, int minus, int multi, int divide) {
    if (cnt == N - 1) {
        MAX = max(MAX, res);
        MIN = min(MIN, res);
    }
    if (plus > 0) dfs(cnt + 1, res + arr[cnt + 1], plus - 1, minus, multi, divide);
    if (minus > 0) dfs(cnt + 1, res - arr[cnt + 1], plus, minus - 1, multi, divide);
    if (multi > 0) dfs(cnt + 1, res * arr[cnt + 1], plus, minus, multi - 1, divide);
    if (divide > 0) dfs(cnt + 1, res / arr[cnt + 1], plus, minus, multi, divide - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> cal[i];
    dfs(0,arr[0],cal[0],cal[1],cal[2],cal[3]);
    cout << MAX<<"\n" << MIN <<"\n";
    return 0;
}