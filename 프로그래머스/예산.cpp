//
// Created by 김종신 on 2020/03/30.
//
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0, s = 0, e = 0, m;
    for(auto a : budgets) e = max(e, a);

    while (s <= e) {
        long long sum = 0;
        m = (s + e) / 2;
        for (auto a: budgets) {
            if (a < m) sum += a;
            else sum += m;
        }
        if (sum < M) s = m + 1, answer = m;
        else e = m - 1;
    }
    return answer;
}