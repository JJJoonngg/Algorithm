//
// Created by 김종신 on 2020/05/06.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int banSize;
bool visit[8];
set<vector<int>> s;

void dfs(int idx, vector<int> num, vector<string> u, vector<string> b) {
    if (idx == banSize) {
        sort(num.begin(), num.end());
        s.insert(num);
        return;
    }
    string cur = b[idx];

    for (int i = 0; i < u.size(); i++) {
        if (visit[i])continue;
        string a = u[i];
        if (cur.length() != a.length()) continue;
        bool flag = true;
        for (int i = 0; i < cur.length(); i++) {
            if (cur[i] == '*') continue;
            if (cur[i] != a[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            visit[i] = true;
            num.push_back(i);
            dfs(idx + 1, num, u, b);
            num.pop_back();
            visit[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    banSize = banned_id.size();
    vector<int> num;
    dfs(0, num, user_id, banned_id);
    int answer = s.size();
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<string> v1, v2;
    v1.push_back("frodo");
    v1.push_back("fradi");
    v1.push_back("crodo");
    v1.push_back("abc123");
    v1.push_back("frodoc");

    v2.push_back("*rodo");
    v2.push_back("*rodo");
    v2.push_back("******");

    cout << solution(v1, v2);
    return 0;
}