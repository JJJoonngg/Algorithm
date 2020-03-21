//
// Created by 김종신 on 2020/03/21.
//
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0, idx = 0;
    priority_queue<int> pq;

    while (stock < k) {
        for (int i = idx; i < dates.size(); i++) {
            if (stock < dates[i]) break;
            pq.push(supplies[i]);
            idx = i + 1;
        }
        stock += pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}