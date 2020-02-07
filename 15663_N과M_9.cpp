//
// Created by 김종신 on 2020/02/07.
//
#include <bits/stdc++.h>

#define MAXI 9
using namespace std;
int N, M, arr[MAXI];
bool visit[MAXI];
vector<int> v;
map<string, int> m;
int idx = 0;

void dfs(int cur) {
    if (v.size() > M) return;
    if (v.size() == M) {
        string cur = "";
        for (int i = 0; i < v.size(); i++) {
            cur += to_string(v[i]) + ",";
        }
        if (m.find(cur) == m.end()) {
            m.insert(make_pair(cur, idx++));
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true, v.push_back(arr[i]);
            dfs(i);
            visit[i] = false, v.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true, v.push_back(arr[i]);
            dfs(i);
            visit[i] = false, v.pop_back();
        }
    }
    return 0;
}