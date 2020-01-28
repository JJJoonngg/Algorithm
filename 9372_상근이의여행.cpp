//
// Created by 김종신 on 2020/01/28.
//
#include <bits/stdc++.h>

#define MAXI 1000 + 1
using namespace std;
int parent[MAXI];
int t, N, M, a, b, res = 0;

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
}

struct info {
    int x, y;
};
vector<info> edge;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        edge.clear();
        res = 0;
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            edge.push_back({a, b});
        }
        for (int i = 0; i <= N; i++) parent[i] = i;
        for (int i = 0; i < edge.size(); i++) {
            info cur = edge[i];
            if (find(cur.x) != find(cur.y)) {
                res++;
                merge(cur.x, cur.y);
            }
        }
        cout << res << "\n";
    }
    return 0;
}