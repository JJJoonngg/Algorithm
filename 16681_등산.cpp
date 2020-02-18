//
// Created by 김종신 on 2020/02/18.
//
#include <bits/stdc++.h>

#define MAXI 100001
#define INF  LLONG_MAX
#define ll long long
#define p pair<long long, int>
using namespace std;
struct info {
    ll num, cost;
};
int N, M, D, E, i;
ll height[MAXI], a, b, c, res = 0, up[MAXI], down[MAXI];
vector<info> route[MAXI];
bool visit[MAXI];

void dijkstra(int s, ll *now) {
    memset(visit, false, sizeof(visit));
    priority_queue<p, vector<p >, greater<p>> pq;
    now[s] = 0;
    pq.push(make_pair(now[s], s));
    while (!pq.empty()) {
        int curNum = pq.top().second;
        pq.pop();
        if (visit[curNum]) continue;
        visit[curNum] = true;
        for (auto next : route[curNum]) {
            if (visit[next.num]) continue;
            if (height[curNum] < height[next.num]) {
                if (now[next.num] > now[curNum] + next.cost) {
                    now[next.num] = now[curNum] + next.cost;
                    pq.push(make_pair(now[next.num], next.num));
                }
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M >> D >> E;
    for (i = 1; i <= N; i++) cin >> height[i];
    for (i = 0; i < M; i++) {
        cin >> a >> b >> c;
        route[a].push_back({b, c});
        route[b].push_back({a, c});
    }
    for (i = 1; i <= N; i++) up[i] = down[i] = INF;
    dijkstra(1, up);
    dijkstra(N, down);
    res = -INF;
    for (i = 2; i < N; i++) {
        if (up[i] == INF || down[i] == INF) continue;
        res = max(res, (height[i] * E) - (up[i] + down[i]) * D);
    }
    res == -INF ? cout << "Impossible\n" : cout << res << "\n";
    return 0;
}