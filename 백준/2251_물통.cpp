//
// Created by 김종신 on 2020/03/09.
//
#include <bits/stdc++.h>

#define MAXI 201
using namespace std;
vector<int> res;
int A, B, C;
struct abc {
    int a, b, c;
};
bool visit[MAXI][MAXI][MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    queue<abc> q;
    q.push({0, 0, C});
    while (!q.empty()) {
        abc cur = q.front();
        q.pop();
        if (visit[cur.a][cur.b][cur.c]) continue;
        visit[cur.a][cur.b][cur.c] = true;

        if (cur.a == 0) res.push_back(cur.c);
        //a->b
        if (cur.a + cur.b > B) q.push({cur.a + cur.b - B, B, cur.c});
        else q.push({0, cur.a + cur.b, cur.c});
        //a->c
        if (cur.a + cur.c > C) q.push({cur.a + cur.c - C, cur.b, C});
        else q.push({0, cur.b, cur.a + cur.c});
        //b->a
        if (cur.a + cur.b > A) q.push({A, cur.a + cur.b - A, cur.c});
        else q.push({cur.a + cur.b, 0, cur.c});
        //b->c
        if (cur.b + cur.c > C) q.push({cur.a, cur.b + cur.c - C, C});
        else q.push({cur.a, 0, cur.b + cur.c});
        //c->a
        if (cur.a + cur.c > A) q.push({A, cur.b, cur.a + cur.c - A});
        else q.push({cur.a + cur.c, cur.b, 0});
        //c->b
        if (cur.b + cur.c > B) q.push({cur.a, B, cur.b + cur.c - B});
        else q.push({cur.a, cur.b + cur.c, 0});
    }
    sort(res.begin(), res.end());
    for (auto a : res)
        cout << a << " ";
    cout << "\n";
    return 0;
}