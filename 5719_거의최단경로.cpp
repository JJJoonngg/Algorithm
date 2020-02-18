//
// Created by 김종신 on 2020/02/18.
//
#include <bits/stdc++.h>

#define INF LLONG_MAX
#define MAXI 501
#define p pair<long long, int>
#define ll long long
using namespace std;
struct info {
    int num;
    ll cost;
};
int N, M, S, D, U, V, P;
ll res1, res2, cost[MAXI];
bool edge[MAXI][MAXI];
vector<info> graph[MAXI];
vector<int> route[MAXI];

void findRoute(int cur) {
    for (auto a: route[cur]) {
        if (edge[a][cur]) continue;
        edge[a][cur] = true;
        findRoute(a);
    }
}

void dijkstra(int s) {
    fill(cost, cost + N, INF);
    cost[s] = 0;
    priority_queue<p, vector<p >, greater<p>> pq;
    pq.push(make_pair(cost[s], s));
    while (!pq.empty()) {
        ll curCost = pq.top().first;
        int curNum = pq.top().second;
        pq.pop();
        for (auto next : graph[curNum]) {
            if (edge[curNum][next.num]) continue;
            if (cost[next.num] > curCost + next.cost) {
                cost[next.num] = curCost + next.cost;
                pq.push(make_pair(cost[next.num], next.num));
                route[next.num].clear();
                route[next.num].push_back(curNum);
            }
            if (cost[next.num] == curCost + next.cost)
                route[next.num].push_back(curNum);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;
        memset(edge, false, sizeof(edge));
        for (int i = 0; i < N; i++) graph[i].clear(), route[i].clear();
        res1 = INF, res2 = INF;
        cin >> S >> D;
        for (int i = 0; i < M; i++) {
            cin >> U >> V >> P;
            graph[U].push_back({V, P});
        }
        dijkstra(S);
        if (cost[D] == INF) {
            cout << "-1\n";
            continue;
        }
        findRoute(D);
        dijkstra(S);
        cost[D] == INF ? cout << "-1\n" : cout << cost[D] << "\n";

    }
    return 0;
}