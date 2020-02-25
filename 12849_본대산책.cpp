//
// Created by 김종신 on 2020/02/24.
//
#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define MAXI 111111
using namespace std;
vector<int> v[8];
ll arr[8][MAXI], D, tmp = 0;

ll dfs(int cur, int time) {
    if (time == D) {
        return cur == 0 ? 1 : 0;
    }
    if (arr[cur][time] != -1) return arr[cur][time];
    arr[cur][time] = 0;
    for (auto next : v[cur]) {
        arr[cur][time] += dfs(next, time + 1);
        arr[cur][time] %= mod;
    }
    return arr[cur][time] %= mod;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> D;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j <= D; j++)
            arr[i][j] = -1;

    v[0].push_back(1), v[0].push_back(2);
    v[1].push_back(0), v[1].push_back(2), v[1].push_back(3);
    v[2].push_back(0), v[2].push_back(1), v[2].push_back(3), v[2].push_back(4);
    v[3].push_back(1), v[3].push_back(2), v[3].push_back(4), v[3].push_back(5);
    v[4].push_back(2), v[4].push_back(3), v[4].push_back(5), v[4].push_back(7);
    v[5].push_back(3), v[5].push_back(4), v[5].push_back(6);
    v[6].push_back(5), v[6].push_back(7);
    v[7].push_back(4), v[7].push_back(6);
    cout << dfs(0, 0) << "\n";
    return 0;
}