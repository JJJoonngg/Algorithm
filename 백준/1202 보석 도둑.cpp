//
// Created by 김종신 on 2020/05/14.
//
#include <bits/stdc++.h>

#define p pair<int,int>
#define ll long long
using namespace std;
int n, k, m, v, c;
ll res = 0;
vector<p > jw;
vector<int> bags;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jw.push_back(make_pair(m, v));
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        bags.push_back(c);
    }
    sort(jw.begin(), jw.end());
    sort(bags.begin(), bags.end());
    priority_queue<int> pq;
    int idx = 0;
    for (auto cur : bags) {
        while (idx < n && jw[idx].first <= cur) pq.push(jw[idx++].second);
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res << "\n";

    return 0;
}