//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct info {
    string s;
    int cnt;
    int num;
};

bool comp1(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

bool comp2(info a, info b) {
    if (a.s == b.s) return a.cnt > b.cnt;
    else return a.s > b.s;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m;
    vector<info> v;
    for (int i = 0; i < genres.size(); i++) {
        if (m.find(genres[i]) == m.end()) {
            m.insert({genres[i], plays[i]});
        } else m.find(genres[i])->second += plays[i];
        v.push_back({genres[i], plays[i], i});
    }
    vector<pair<string, int>> v2(m.begin(), m.end());
    sort(v2.begin(), v2.end(), comp1);
    sort(v.begin(), v.end(), comp2);
    vector<int> answer;

    for (int i = 0; i < v2.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v2[i].first == v[j].s) {
                answer.push_back(v[j].num);
                cnt++;
            }
            if (cnt == 2) break;
        }
    }
    return answer;
}