//
// Created by 김종신 on 2020/05/06.
//
#include <string>
#include <stack>

using namespace std;

bool judgeCollect(string u) {
    stack<char> s;
    for (auto cur : u) {
        if (cur == '(') {
            s.push('(');
        } else {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return true;
}

string solve(string w) {
    if (!(w.length())) return w;
    string res = "";
    int cnt = 0, l = 0, r = 0;
    for (auto cur : w) {
        if (cur == '(') l++;
        else if (cur == ')')r++;
        if (l != 0 && l == r) {
            break;
        }
        cnt++;
    }
    string u = w.substr(0, cnt + 1);
    string v = w.substr(cnt + 1);

    if (judgeCollect(u)) {
        res += u + solve(v);
    } else {
        string tmp = "(" + solve(v) + ")";
        string u2 = u.substr(1, u.length() - 2);
        string u3 = "";
        for (auto cur : u2) {
            if (cur == '(') u3 += ")";
            else u3 += "(";
        }
        res += tmp + u3;
    }
    return res;
}

string solution(string p) {
    string answer = solve(p);
    return answer;
}