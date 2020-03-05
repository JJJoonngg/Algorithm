//
// Created by 김종신 on 2019/11/26.
//
#include <bits/stdc++.h>

#define INF 1e9
#define MAXI 51
using namespace std;

struct xy {
    int x, y;
};
int n, m, res;
bool visit[MAXI];
int arr[MAXI][MAXI];
vector<xy> home;
vector<xy> store;

int calculate(xy tmp1, xy tmp2) { return abs(tmp1.x - tmp2.x) + abs(tmp1.y - tmp2.y); }

void dfs(int cnt, int cur) {
    if(cur > store.size()) return;
    if (cnt == m) {
        int sum = 0;
        for (int i = 0; i < home.size(); i++) {
            int dist = INF;
            for (int j = 0; j < store.size(); j++) {
                if (visit[j]) {
                    int tmp = calculate(home[i], store[j]);
                    dist = min(dist, tmp);
                }
            }
            sum += dist;
        }
        res = min(res, sum);
        return;
    }
    visit[cur] = true;
    dfs(cnt + 1, cur+1);
    visit[cur] = false;
    dfs(cnt , cur+1);

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) home.push_back({i, j});
            if (arr[i][j] == 2) store.push_back({i, j});
        }
    }
    res = INF;

    dfs(0,0);

    cout << res << "\n";
    return 0;
}