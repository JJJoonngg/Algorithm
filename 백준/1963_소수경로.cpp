//
// Created by 김종신 on 2020/10/06.
//
#include <bits/stdc++.h>

#define MAXI 10001

using namespace std;
int T, s, e, res[MAXI];
bool prime[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    for (int i = 2; i * i <= MAXI; i++) for (int j = i * i; j < MAXI; j += i) prime[j] = true;
    cin >> T;
    while (T--) {
        cin >> s >> e;
        memset(res, -1, sizeof(res));
        queue<int> q;
        q.push(s);
        res[s] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                string curS = to_string(cur);
                for (int j = 0; j < 10; j++) {
                    curS[i] = j + '0';
                    int next = stoi(curS);
                    if (next >= 1000 && !prime[next] && res[next] == -1)
                        res[next] = res[cur] + 1, q.push(next);
                }
            }
        }
        if (res[e] == -1) cout << "Impossible\n";
        else cout << res[e] << "\n";
    }
    return 0;
}