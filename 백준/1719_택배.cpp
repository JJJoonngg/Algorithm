//
// Created by 김종신 on 2020/02/18.
//
#include <bits/stdc++.h>

#define MAXI 201
#define INF 1e9
#define p pair<int, int>
using namespace std;
vector<p > v[MAXI];
int n, m, a, b, c, cost[MAXI], res[MAXI][MAXI], route[MAXI];;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    priority_queue<p, vector<p >, greater<p>> pq;
    for (int i = 1; i <= n; i++) {
        fill(cost, cost + n + 1, INF);
        cost[i] = 0;
        pq.push(make_pair(cost[i], i));
        while (!pq.empty()) {
            p cur = pq.top();
            pq.pop();
            if (cost[cur.second] < cur.first) continue;
            for (auto next : v[cur.second]) {
                if (cost[next.first] > cur.first + next.second) {
                    cost[next.first] = cur.first + next.second;
                    pq.push(make_pair(cost[next.first], next.first));
                    route[next.first] = cur.second;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else {
                int cur = j;
                while (route[cur] != i) {
                    cur = route[cur];
                }
                cout << cur << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}