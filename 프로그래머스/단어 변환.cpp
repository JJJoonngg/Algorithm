//
// Created by 김종신 on 2020/03/30.
//
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define MAXI 1e9
using namespace std;

int res = MAXI;
bool flag = false, visit[51];
map<string, int> m;
string s, e;

bool checkDif(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            cnt++;
    }
    if (cnt == 1) return true;
    else return false;
}

void dfs(string cur, int cnt, vector<string> &v) {
    if (!cur.compare(e)) {
        flag = true;
        res = min(res, cnt);
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (visit[i]) continue;
        if (!s.compare(v[i])) continue;
        if (!cur.compare(v[i])) continue;
        if (!checkDif(cur, v[i])) continue;
        if (m.find(v[i])->second < cnt + 1) continue;
        m.find(v[i])->second = cnt + 1;
        dfs(v[i], cnt + 1, v);
    }
}


int solution(string begin, string target, vector<string> words) {
    int answer = MAXI;
    s = begin, e = target;
    for (auto a : words) {
        if (!a.compare(target)) {
            flag = true;
        }
        m.insert(make_pair(a, MAXI));
    }
    if (!flag) {
        return 0;
    }
    flag = false;

    for (int i = 0; i < words.size(); i++) {
        if (checkDif(words[i], s)) {
            m.find(words[i])->second = 1;
            dfs(words[i], 1, words);
        }
    }
    if (!flag) {
        return 0;
    }
    answer = min(answer, res);

    return answer;
}