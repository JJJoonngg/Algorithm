//
// Created by 김종신 on 2020/02/15.
//
#include <bits/stdc++.h>

#define MAXI 801
#define INF 1e9
#define p pair<int,int>
using namespace std;
struct info {
    int num, cost;
};
vector<info> graph[MAXI];
int cost[MAXI] = {0,}, a, b, c, n, e, X, Y;

vector<int> findRoute(int s, int e) {
    vector<int> v;
    priority_queue<p, vector<p >, greater<p>> pq;
    for (int i = 1; i <= n; i++) cost[i] = INF;
    cost[s] = 0;
    pq.push(make_pair(cost[s], s));
    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNum = pq.top().second;
        pq.pop();
        if (cost[curNum] < curCost) continue;
        for (auto next : graph[curNum]) {
            if (curCost + next.cost < cost[next.num]) {
                cost[next.num] = curCost + next.cost;
                pq.push(make_pair(cost[next.num], next.num));
            }
        }
    }
    for (int i = 0; i <= e; i++) {
        v.push_back(cost[i]);
    }
    return v;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> X >> Y;
    int ans = 0;
    vector<int> toN = findRoute(1, n);
    vector<int> XtoN = findRoute(X, n);
    vector<int> YtoN = findRoute(Y, n);

    ans = min(toN[X] + XtoN[Y] + YtoN[n], toN[Y] + YtoN[X] + XtoN[n]);
    if (ans >= INF || ans < 0) ans = -1;
    cout << ans << "\n";
    return 0;
}