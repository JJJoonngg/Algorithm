//
// Created by 김종신 on 21. 3. 24..
//
#include <bits/stdc++.h>

#define MAXI 1000001
using namespace std;

int n, a, b, check[2][MAXI];
vector<int> v[MAXI], v2[MAXI];

int func(int cur, bool isEarly) {
    if (v2[cur].empty()) {
        if (isEarly) return 1;
        return 0;
    }
    if (check[isEarly][cur] != -1) return check[isEarly][cur];

    if (isEarly) {
        check[isEarly][cur] = 1;
        for (auto child : v2[cur]) {
            check[isEarly][cur] += min(func(child, false), func(child, true));
        }
    } else {
        check[isEarly][cur] = 0;
        for (auto child :v2[cur]) {
            check[isEarly][cur] += func(child, true);
        }
    }
    return check[isEarly][cur];
}

void makeTree(int cur, int parent) {
    if (parent != 0) v2[parent].push_back(cur);
    for (auto _next:v[cur]) {
        if (_next != parent) {
            makeTree(_next, cur);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }
    makeTree(1, 0);
    memset(check, -1, sizeof(check));
    int res = min(func(1, true), func(1, false));
    cout << res << "\n";
    return 0;
}