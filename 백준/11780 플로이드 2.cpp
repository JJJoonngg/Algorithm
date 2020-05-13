//
// Created by 김종신 on 2020/05/13.
//
#include <bits/stdc++.h>

#define MAXI 101
#define INF 1e9
using namespace std;

int n, m, a, b, c, arr[MAXI][MAXI], route[MAXI][MAXI];
vector<int> v;

void findRoute(int from, int to) {
    if (!route[from][to]) {
        v.push_back(from);
        if (from != to) v.push_back(to);
        return;
    }
    findRoute(from, route[from][to]);
    v.pop_back();
    findRoute(route[from][to], to);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j], route[i][j] = k;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == INF)cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "0\n";
                continue;
            }
            findRoute(i, j);
            cout << v.size() << " ";
            for (auto cur : v)
                cout << cur << " ";
            cout << "\n";
            v.clear();
        }
    }

    return 0;
}
