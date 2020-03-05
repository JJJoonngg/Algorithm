//
// Created by 김종신 on 2020/02/06.
//
#include <bits/stdc++.h>

#define MAXI 2001
using namespace std;
int N, M, a, b;
vector<int> v[MAXI];
bool visit[MAXI], flag = false;

void dfs(int cur, int cnt) {
    if (cnt == 4) {
        flag = true;
        return;
    }
    visit[cur] = true;
    for (auto next : v[cur])
        if (!visit[next]) {
            dfs(next, cnt + 1);
            if(flag) return;
        }
    visit[cur] = false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    while (M--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        memset(visit, false, sizeof(visit));
        visit[i] = true;
        dfs(i, 0);
        if(flag) break;
    }
    cout << flag << "\n";
    return 0;
}