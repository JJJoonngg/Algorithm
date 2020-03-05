//
// Created by 김종신 on 2020/02/19.
//
#include <bits/stdc++.h>

#define MAXI 1001
#define INF 2e9
using namespace std;
int N, M, A, B, K, G, U, V, L, cost[MAXI], cur;
int arr[MAXI][MAXI], king[MAXI][MAXI];
bool visit[MAXI];
vector<int> go;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    cin >> A >> B >> K >> G;
    fill(cost, cost + N + 1, INF);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            arr[i][j] = king[i][j] = INF;
    memset(visit, false, sizeof(visit));
    while (G--) {
        int input;
        cin >> input;ㅈ
        go.push_back(input);
    }
    while (M--) {
        cin >> U >> V >> L;
        arr[U][V] = arr[V][U] = L;
    }
    cur = 0;
    for (int i = 0; i < go.size() - 1; i++) {
        king[go[i]][go[i + 1]] = king[go[i + 1]][go[i]] = cur;
        cur += arr[go[i]][go[i + 1]];
    }
    cost[A] = K;
    for (int i = 1; i <= N; i++) {
        int cur = 0;
        for (int j = 1; j <= N; j++) {
            if (visit[j]) continue;
            if (cur == 0 || cost[j] < cost[cur]) cur = j;
        }
        visit[cur] = true;
        for (int j = 1; j <= N; j++) {
            if (cost[cur] < king[cur][j]) cost[j] = min(cost[j], cost[cur] + arr[cur][j]);
            else cost[j] = min(cost[j], max(king[cur][j] + arr[cur][j], cost[cur]) + arr[cur][j]);
        }
    }
    cout << cost[B] - cost[A] << "\n";
    return 0;
}