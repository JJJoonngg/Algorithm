//
// Created by 김종신 on 2020/03/30.
//
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#define MAXI 20001
#define INF 1e9
#define t pair<int, long long>
#define ll long long
using namespace std;

vector<int> node[MAXI];
ll cost[MAXI];
struct a {
    int num;
    ll cost;
};
priority_queue<t, vector<t >, greater<t>> pq;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (auto cur : edge) {
        node[cur[0]].push_back(cur[1]);
        node[cur[1]].push_back(cur[0]);
    }
    fill(cost, cost + MAXI, INF);
    cost[1] = 0;
    pq.push({1, 0});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        for (auto now : node[cur.first]) {
            if (cur.second + 1 < cost[now]) {
                cost[now] = cur.second + 1;
                pq.push({now, cost[now]});
            }
        }
    }
    ll tmp = 0;
    for (int i = 2; i <= n; i++) {
        if (cost[i] == INF) continue;
        tmp = max(tmp, cost[i]);
    }
    for (int i = 2; i <= n; i++) {
        if (tmp == cost[i])
            answer++;
    }
    return answer;
}