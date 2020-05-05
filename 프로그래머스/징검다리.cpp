//
// Created by 김종신 on 2020/04/04.
//
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0, s = 1, e = distance, m;
    sort(rocks.begin(), rocks.end());

    while (s <= e) {
        int cnt = 0, prev = 0;
        m = (s + e) / 2;
        for (auto cur : rocks) {
            if (cur - prev < m) cnt++;
            else prev = cur;
        }

        if (distance - prev < m) cnt++;
        if (cnt <= n) {
            answer = max(answer, m);
            s = m + 1;
        } else e = m - 1;
    }

    return answer;
}