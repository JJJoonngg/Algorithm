//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (auto cur : citations) {
        if (cur <= answer) break;
        answer++;
    }
    return answer;
}