//
// Created by 김종신 on 2020/02/20.
//
#include <bits/stdc++.h>

#define INF 2e9
#define MAXI 126
using namespace std;
int N;
int arr[MAXI][MAXI], cost[MAXI][MAXI];
bool visit[MAXI][MAXI];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int idx = 1;
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        fill(&cost[0][0], &cost[MAXI][MAXI], INF);
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> arr[i][j];
        cost[0][0] = arr[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int curCost = pq.top().first;
            pair<int, int> curXY = pq.top().second;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curXY.first + dx[i];
                int ny = curXY.second + dy[i];
                if (checkRange(nx, ny)) {
                    if (!visit[nx][ny] && cost[nx][ny] > arr[nx][ny] + curCost) {
                        visit[nx][ny] = true;
                        cost[nx][ny] = arr[nx][ny] + curCost;
                        pq.push({cost[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        cout << "Problem " << idx++ << ": " << arr[0][0] + cost[N - 1][N - 1] << "\n";
    }

    return 0;
}