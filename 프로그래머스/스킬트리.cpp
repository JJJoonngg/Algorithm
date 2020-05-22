//
// Created by 김종신 on 2020/05/22.
//
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    queue<char> q;
    for (auto cur : skill_trees) {
        for (auto a : cur) {
            for (auto b : skill) {
                if (a == b) q.push(b);
            }
        }
        if (q.empty()) answer++;
        int siz = q.size(), cnt = 0, idx = 0;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            if (skill[idx] == c) cnt++;
            if (cnt == siz) {
                answer++;
                break;
            }
            idx++;
        }
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    return 0;
}