//
// Created by 김종신 on 2020/06/01.
//
#include <bits/stdc++.h>

using namespace std;
int N, M, K, a, b, c;
deque<int> dq[11][11];
int arr[11][11], arr2[11][11];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j], arr2[i][j] = 5;

    while (M--) {
        cin >> a >> b >> c;
        dq[--a][--b].push_back(c);
    }

    while (K--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!dq[i][j].empty()) {
                    int tmp = 0, siz = dq[i][j].size();
                    sort(dq[i][j].begin(), dq[i][j].end());
                    while (siz--) {
                        int cur = dq[i][j].front();
                        dq[i][j].pop_front();
                        if (arr2[i][j] >= cur) {
                            arr2[i][j] -= cur;
                            dq[i][j].push_back(++cur);
                        } else tmp += cur / 2;
                    }
                    arr2[i][j] += tmp;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto cur : dq[i][j]) {
                    if (!(cur % 5)) {
                        for (int t = 0; t < 8; t++) {
                            int nx = j + dx[t], ny = i + dy[t];
                            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                                dq[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) arr2[i][j] += arr[i][j];
    }

    int res = 0;
    for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) res += dq[i][j].size();
    cout << res << "\n";

    return 0;
}