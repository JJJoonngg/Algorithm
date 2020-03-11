//
// Created by 김종신 on 2020/03/09.
//
#include <bits/stdc++.h>

#define mod 10000
using namespace std;
int A, B, T;
bool visit[mod + 1];
struct info {
    int x;
    string res;
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        memset(visit, false, sizeof(visit));
        cin >> A >> B;
        queue<info> q;
        q.push({A, ""});
        visit[A] = true;
        while (!q.empty()) {
            info cur = q.front();
            q.pop();
            if (cur.x == B) {
                cout << cur.res << "\n";
                break;
            }
            if (!visit[(cur.x * 2) % mod]) visit[(cur.x * 2) % mod] = true, q.push({(cur.x * 2) % mod, cur.res + "D"});
            if (cur.x == 0 && !visit[9999])visit[9999] = true, q.push({9999, cur.res + "S"});
            if (cur.x != 0) {
                if (!visit[cur.x - 1]) visit[cur.x - 1] = true, q.push({cur.x - 1, cur.res + "S"});
                if (!visit[(cur.x % 1000) * 10 + cur.x / 1000])
                    visit[(cur.x % 1000) * 10 + cur.x / 1000] = true, q.push(
                            {(cur.x % 1000) * 10 + cur.x / 1000, cur.res + "L"});
                if (!visit[cur.x / 10 + (cur.x % 10) * 1000])
                    visit[cur.x / 10 + (cur.x % 10) * 1000] = true, q.push(
                            {cur.x / 10 + (cur.x % 10) * 1000, cur.res + "R"});
            }
        }
    }
    return 0;
}