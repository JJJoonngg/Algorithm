//
// Created by 김종신 on 2020/02/23.
//
#include <bits/stdc++.h>

#define dd double
#define p pair<dd, int>
#define INF DBL_MAX
#define MAXI 111
using namespace std;
dd cost[MAXI];
bool check[MAXI];
struct xy {
    dd x, y;
};
xy info[MAXI], s, e;
int N;

dd calDist(int a, int b) { return sqrt(pow(info[a].x - info[b].x, 2) + pow(info[a].y - info[b].y, 2)); }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> s.x >> s.y >> e.x >> e.y >> N;
    for (int i = 1; i <= N; i++)
        cin >> info[i].x >> info[i].y;
    info[0] = s;
    info[N + 1] = e;
    fill(cost, cost + MAXI, INF);
    cost[0] = 0;
    priority_queue<p, vector<p >, greater<p>> pq;
    pq.push({cost[0], 0});
    bool checkCur = true;
    while (!pq.empty()) {
        p cur = pq.top();
        pq.pop();
        if(check[cur.second]) continue;
        check[cur.second] = true;
        for (int idx = 1; idx <= N + 1; idx++) {
            dd a = calDist(cur.second, idx);
            dd curTime = checkCur ? a / 5.0 : min(a / 5.0, 2.0 + abs(a - 50) / 5.0);
            if (cost[idx] > cost[cur.second] + curTime) {
                cost[idx] = cost[cur.second] + curTime;
                pq.push({cost[idx], idx});
            }
        }
        checkCur = false;
    }
    cout << fixed << setprecision(6) << cost[N + 1] << "\n";

    return 0;
}