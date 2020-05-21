//
// Created by 김종신 on 2020/05/21.
//
#include <bits/stdc++.h>

#define p pair<int,int>
#define MAXI 1000000+1
using namespace std;
int F, S, G, U, D, res = -1;
bool visit[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> F >> S >> G >> U >> D;
    visit[S] = true;
    queue<p > q;
    q.push({S, 0});
    while (!q.empty()) {
        p cur = q.front();
        q.pop();
        if (cur.first == G) {
            res = cur.second;
            break;
        }
        if (cur.first + U <= F && !visit[cur.first + U])
            q.push({cur.first + U, cur.second + 1}), visit[cur.first + U] = true;
        if (cur.first - D > 0 && !visit[cur.first - D])
            q.push({cur.first - D, cur.second + 1}), visit[cur.first - D] = true;
    }
    if (res == -1) cout << "use the stairs\n";
    else cout << res << "\n";
    return 0;
}