//
// Created by 김종신 on 2020/01/28.
//
#include <bits/stdc++.h>

#define MAXI 1000 + 1
using namespace std;
int N, M, a, b, c;
long long res = 0;
struct info {
    int x, y, cost;
};

bool comp(info tmp1, info tmp2) { return tmp1.cost < tmp2.cost; }

vector<info> edge;
int parent[MAXI], setNum[MAXI];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
    setNum[x] += setNum[y];
    setNum[y] = 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }
    for (int i = 0; i < N; i++) parent[i] = i, setNum[i] = 1;
    sort(edge.begin(), edge.end(), comp);
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