//
// Created by 김종신 on 2020/02/18.
//
#include <bits/stdc++.h>

#define MAXI 1001
#define p pair<int, int>
#define INF 1e9
using namespace std;
struct info {
    int num, cost;
};
vector<info> net[MAXI];
vector<p > res;
int N, M, A, B, C, cost[MAXI], route[MAXI];
bool visit[MAXI][MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    fill(cost, cost + N + 1, INF);
    fill(route, route + N + 1, 0);
    while (M--) {
        cin >> A >> B >> C;
        net[A].push_back({B, C});
        net[B].push_back({A, C});
    }
    cost[1] = 0;
    priority_queue<p, vector<p >, greater<p>> pq;
    pq.push(make_pair(cost[1], 1));
    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNum = pq.top().second;
        pq.pop();
        if (curCost > cost[curNum])continue;
        for (auto next: net[curNum]) {
            if (cost[next.num] > curCost + next.cost) {
                cost[next.num] = curCost + next.cost;
                route[next.num] = curNum;
                pq.push(make_pair(cost[next.num], next.num));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        int cur = i;
        while (cur != 0) {
            if (!visit[cur][route[cur]] && route[cur] != 0) {
                visit[cur][route[cur]] = visit[route[cur]][cur] = true;
                res.push_back({cur, route[cur]});
            }
            cur = route[cur];
        }
    }
    cout << res.size() << "\n";
    for (auto next : res)
        cout << next.first << " " << next.second << "\n";

    return 0;
}