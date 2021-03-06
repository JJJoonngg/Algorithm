//
// Created by 김종신 on 2020/01/28.
//
#include <bits/stdc++.h>

#define MAXI 10000 + 1
using namespace std;
int V, E, A, B, C;
int parent[MAXI], num[MAXI];
long long res = 0;
struct info {
    int x, y, cost;
};

bool comp(info tmp1, info tmp2) {
    return tmp1.cost < tmp2.cost;
}

vector <info> edge;

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (num[x] < num[y]) swap(x, y);
        parent[y] = x;
        num[x] += num[y];
        num[y] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        edge.push_back({A, B, C});
    }
    sort(edge.begin(), edge.end(), comp);
    for (int i = 0; i < V; i++) { parent[i] = i, num[i] = 1; }

    for (int i = 0; i < edge.size(); i++) {
        info tmp = edge[i];
        if (find(tmp.x) != find(tmp.y)) {
            res += tmp.cost;
            merge(tmp.x, tmp.y);
        }
    }
    cout << res << "\n";
    return 0;
}
