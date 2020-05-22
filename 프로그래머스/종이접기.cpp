//
// Created by 김종신 on 2020/05/22.
//
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    if (n == 1) return answer;
    n--;
    while (n--) {
        vector<int> tmp;
        for (int i = answer.size() - 1; i >= 0; i--) {
            if (answer[i] == 0) tmp.push_back(1);
            else tmp.push_back(0);
        }
        answer.push_back(0);
        for (auto a : tmp)
            answer.push_back(a);
    }
    return answer;
}