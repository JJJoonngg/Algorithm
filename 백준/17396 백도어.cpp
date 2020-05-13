//
// Created by 김종신 on 2020/05/13.
//
#include <bits/stdc++.h>

#define MAXI 100001
#define INF LONG_MAX
#define p pair<long long, long long>
using namespace std;
struct info {
    long long node, cost;
};
long long n, m, a, b, t;
vector<info> graph[MAXI];
long long arr[MAXI], cost[MAXI];
bool visit[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    arr[n - 1] = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        if (arr[a] || arr[b]) continue;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
    cost[0] = 0;
    for (int i = 1; i < n; i++) cost[i] = INF;
    priority_queue<p, vector<p >, greater<p>> pq;
    pq.push({cost[0], 0});
    while (!pq.empty()) {
        p cur = pq.top();
        pq.pop();
        if (visit[cur.second]) continue;
        for (auto next : graph[cur.second]) {
            if (cost[next.node] > cur.first + next.cost && !visit[next.node]) {
                cost[next.node] = cur.first + next.cost;
                pq.push({cost[next.node], next.node});
            }
        }
        visit[cur.second] = true;
    }
    if (cost[n - 1] == INF) cost[n - 1] = -1;
    cout << cost[n - 1] << "\n";
    return 0;
}