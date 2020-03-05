//
// Created by 김종신 on 2020/01/28.
//
#include <bits/stdc++.h>

#define MAXI 100000 + 1
using namespace std;
int N, M, A, B, C, parent[MAXI];
long long res = 0;
struct info {
    int x, y, cost;
};

bool comp(info x, info y) { return x.cost < y.cost; }

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

vector<info> edge;

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edge.push_back({A, B, C});
    }
    sort(edge.begin(), edge.end(), comp);
    for (int i = 0; i <= N; i++) parent[i] = i;
    for (int i = 0, cnt = 0; i < edge.size(); i++) {
        if (cnt == N - 2) break;
        if (find(edge[i].x) != find(edge[i].y)) {
            res += edge[i].cost;
            merge(edge[i].x, edge[i].y);
            cnt++;
        }
    }
    cout << res << "\n";
    return 0;
}