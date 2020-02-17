//
// Created by 김종신 on 2020/02/17.
//
//역순으로 쪼개진 것들을 합치면서 set의 size를 이용하여 값을 계산하는 disjoint-set 문제
//
#include <bits/stdc++.h>

#define MAXI 100001
#define ll long long
using namespace std;
struct info {
    int x, y;
};
vector<info> connections;
stack<int> s;
bool nonCon[MAXI];
int parent[MAXI];
int n, m, q, a, x, y;
ll res = 0, siz[MAXI], tmp;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    parent[y] = x;
    res += siz[x] * siz[y];
    siz[x] += siz[y];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) parent[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        connections.push_back({x - 1, y - 1});
    }
    for (int i = 1; i <= q; i++) {
        cin >> a;
        nonCon[a - 1] = true;
        s.push(a - 1);
    }
    for (int i = 0; i < m; i++) {
        if (nonCon[i]) continue;
        merge(connections[i].x, connections[i].y);
    }
    res = 0;
    while (!s.empty()) {
        int num = s.top();
        s.pop();
        merge(connections[num].x, connections[num].y);
    }
    cout << res << "\n";
    return 0;
}