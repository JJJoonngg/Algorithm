//
// Created by 김종신 on 2020/03/21.
//
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto cur : scoville)
        pq.push(cur);


    while (!pq.empty()) {
        if (pq.size() < 2) break;
        int first = pq.top();
        pq.pop();
        if (first >= K) {
            break;
        }
        int second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        answer++;
    }

    if (pq.size() != 0 && pq.top() < K) answer = -1;
    return answer;
}