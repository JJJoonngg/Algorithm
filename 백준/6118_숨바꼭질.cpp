//
// Created by 김종신 on 2020/02/18.
//
#include <bits/stdc++.h>

#define MAXI 20001
#define INF 1e9
#define p pair<int,int>
using namespace std;
int N, M, res, cnt, cost[MAXI], a, b;
vector<int> graph[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    fill(cost, cost + N + 1, INF);
    priority_queue<p, vector<p >, greater<p>> pq;
    cost[1] = 0;
    pq.push(make_pair(cost[1], 1));
    while (!pq.empty()) {
        int curNum = pq.top().second;
        int curCnt = pq.top().first;
        pq.pop();
        for (auto next : graph[curNum]) {
            if (cost[next] > curCnt + 1) {
                cost[next] = curCnt + 1;
                pq.push(make_pair(curCnt + 1, next));
            }
        }
    }
    res = 1, cnt = 1;
    for (int i = 2; i <= N; i++) {
        if (cost[res] < cost[i]) {
            res = i;
            cnt = 1;
        } else if (cost[res] == cost[i])
            cnt++;
    }
    cout << res << " " << cost[res] << " " << cnt << "\n";
    return 0;
}