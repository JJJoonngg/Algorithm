//
// Created by 김종신 on 2020/05/11.
//
#include <bits/stdc++.h>

using namespace std;
int t, n, x, y;
bool visit[103];
vector<pair<int, int>> v;
vector<int> graph[103];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        for (int i = 0; i < n + 2; i++) {
            cin >> x >> y;
            v.push_back({x, y});
            graph[i].clear(), visit[i] = false;
        }
        for (int i = 0; i < n + 1; i++)
            for (int j = i + 1; j < n + 2; j++)
                if (((abs(v[i].first - v[j].first) / 50.0) + (abs(v[i].second - v[j].second) / 50.0)) <= 20)
                    graph[i].push_back(j), graph[j].push_back(i);

        queue<int> q;
        q.push(0), visit[0] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto a : graph[cur]) {
                if (!visit[a])
                    q.push(a), visit[a] = true;
            }
        }
        if (visit[n + 1]) cout << "happy\n";
        else cout << "sad\n";
    }
    return 0;
}