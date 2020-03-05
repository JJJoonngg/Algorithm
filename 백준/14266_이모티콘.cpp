//
// Created by 김종신 on 2020/03/01.
//
#include <bits/stdc++.h>

using namespace std;
int S, res = 0;
bool visit[1001][1001];
struct in {
    int board, len;
};
queue<in> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> S;
    q.push({1, 0});
    visit[0][1] = true;
    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            in cur = q.front();
            q.pop();
            if (cur.len == S) {
                cout << res << "\n";
                return 0;
            }
            q.push({cur.len, cur.len});
            if (cur.board > 0) {
                if (!visit[cur.board][cur.len + cur.board] && cur.len + cur.board <= 1000) {
                    q.push({cur.board, cur.board + cur.len});
                    visit[cur.board][cur.len + cur.board] = true;
                }
            }
            if (!visit[cur.board][cur.len - 1] && cur.len > 2) {
                visit[cur.board][cur.len - 1] = true;
                q.push({cur.board, cur.len - 1});
            }

        }
        res++;
    }

    return 0;
}