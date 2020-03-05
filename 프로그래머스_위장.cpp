//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<pair<int, string>> v;
    for (int i = 0; i < clothes.size(); i++) {
        bool flag = false;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].second == clothes[i][1]) {
                v[j].first++;
                flag = true;
                break;
            }
        }
        if (!flag) v.push_back({1, clothes[i][1]});
    }
    for (auto cur : v) {
        answer *= (cur.first + 1);
    }
    answer--;
    return answer;
}