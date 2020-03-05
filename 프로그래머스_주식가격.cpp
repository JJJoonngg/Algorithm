//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                answer[i] = j - i;
                break;
            }
            if (j == prices.size() - 1) answer[i] = j - i;
        }
    }
    return answer;
}