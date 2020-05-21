//
// Created by 김종신 on 2020/05/21.
//
#include <bits/stdc++.h>

#define MAXI 101
using namespace std;
int n, m, a, b, x, y;
int dis[MAXI];
bool arr[MAXI][MAXI], visit[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> a >> b >> m;
    while (m--) {
        cin >> x >> y;
        arr[x][y] = arr[y][x] = true;
    }
    queue<int> q;
    q.push(a), visit[a] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) if (arr[cur][i] && !visit[i]) visit[i] = true, dis[i] = dis[cur] + 1, q.push(i);
    }
    if (dis[b] == 0) dis[b] = -1;
    cout << dis[b] << "\n";
    return 0;
}