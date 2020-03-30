//
// Created by 김종신 on 2020/03/30.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visit;
vector<string> res;

bool dfs(string cur, vector<vector<string>> &v, vector<string> &tmp, int cnt) {
    tmp.push_back(cur);
    if (v.size() == cnt) {
        res = tmp;
        return true;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i][0] == cur && !visit[i]) {
            visit[i] = true;
            if(dfs(v[i][1], v, tmp, cnt + 1)) return true;
            visit[i] = false;
        }
    }
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    visit.resize(tickets.size() + 1);
    fill(visit.begin(), visit.end(), false);

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, tmp, 0);
    answer = res;
    return answer;
}