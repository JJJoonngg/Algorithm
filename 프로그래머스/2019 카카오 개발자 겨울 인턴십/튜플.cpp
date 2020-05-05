//
// Created by 김종신 on 2020/05/05.
//
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer, tmp;
    vector<vector<int>> v;
    set<int> ss;
    int cur = 0, num;
    bool flag = false;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') continue;
        if (s[i] == '}' || s[i] == ',') {
            if (!flag) continue;
            flag = false;
            if (i - cur == 1)num = s[cur] - '0';
            else num = stoi(s.substr(cur, i - cur));
            tmp.push_back(num);
            if (s[i] == '}') {
                v.push_back(tmp);
                tmp.clear();
            }
        } else {
            if (flag) continue;
            cur = i;
            flag = true;
        }
    }
    sort(v.begin(), v.end(), comp);

    for (auto a : v) {
        sort(a.begin(), a.end());
        for (auto b : a) {
            if (ss.find(b) == ss.end()) {
                ss.insert(b);
                answer.push_back(b);
            }
        }
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<int> v = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    for (auto a: v)
        cout << a << " ";
    return 0;
}