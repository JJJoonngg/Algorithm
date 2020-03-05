//
// Created by 김종신 on 2020/02/17.
//
//disjoint-set 문제
#include <bits/stdc++.h>

#define MAXI 10001
using namespace std;
int n, m, k, a, b, cost[MAXI], parent[MAXI], res = 0;

int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    cost[x] < cost[y] ? parent[y] = x : parent[x] = y;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i <= n; i++) parent[i] = -1;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        merge(a, b);
    }
    for (int i = 1; i <= n; i++)
        if (parent[i] == -1)
            res += cost[i];

    k < res ? cout << "Oh no\n" : cout << res << "\n";
    return 0;
}