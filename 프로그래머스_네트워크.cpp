//
// Created by 김종신 on 24/10/2019.
//
#include <bits/stdc++.h>

#define MAXI 200 + 1
using namespace std;
bool visit[MAXI];
int siz;

void dfs(int cur, vector<vector<int>> &v) {
    visit[cur] = true;
    for (int i = 0; i < siz; i++) {
        if (i == cur) continue;
        if (v[cur][i] && !visit[i]) {
            dfs(i, v);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    siz = n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!visit[j] && computers[i][j]) {
                dfs(j, computers);
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<int> tmp;
    vector<vector<int>> v;
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    v.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    v.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(1);
    v.push_back(tmp);
    tmp.clear();
    cout << solution(3, v) << "\n";
    return 0;
}