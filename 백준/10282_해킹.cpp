//
// Created by 김종신 on 2020/02/18.
//
#include <bits/stdc++.h>

#define MAXI 10001
#define INF 1e9
#define p pair<int, int>
using namespace std;
int n, d, c, a, b, s, t, cost[MAXI];
vector<p > v[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        for (int i = 1; i <= n; i++) v[i].clear();
        fill(cost, cost + n + 1, INF);
        while (d--) {
            cin >> a >> b >> s;
            v[b].push_back(make_pair(a, s));
        }
        cost[c] = 0;
        priority_queue<p, vector<p >, greater<p>> pq;
        pq.push(make_pair(cost[c], c));
        while (!pq.empty()) {
            p cur = pq.top();
            pq.pop();
            if (cost[cur.second] < cur.first) continue;
            for (auto next : v[cur.second]) {
                if (cost[next.first] > cur.first + next.second) {
                    cost[next.first] = cur.first + next.second;
                    pq.push(make_pair(cost[next.first], next.first));
                }
            }
        }
        int res = -INF, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (cost[i] == INF)continue;
            res = max(res, cost[i]);
            cnt++;
        }
        cout << cnt << " " << res << "\n";
    }
    return 0;
}