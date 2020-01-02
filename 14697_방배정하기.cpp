//
// Created by 김종신 on 2019/12/31.
// Solved by using DFS Algorithm
//
#include <bits/stdc++.h>

#define MAXI 300 + 1
using namespace std;
int a, b, c, n;
bool flag[MAXI];

void dfs(int cnt1, int cnt2, int cnt3) {
    int tmp = cnt1 * a + cnt2 * b + cnt3 * c;
    if (tmp > 300) return;
    flag[tmp] = true;
    if (!flag[tmp + a])dfs(cnt1 + 1, cnt2, cnt3);
    if (!flag[tmp + b])dfs(cnt1, cnt2 + 1, cnt3);
    if (!flag[tmp + c])dfs(cnt1, cnt2, cnt3 + 1);
    else return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c >> n;

    dfs(0, 0, 0);
    cout << flag[n] << "\n";
    return 0;
}

