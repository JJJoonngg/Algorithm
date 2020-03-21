//
// Created by 김종신 on 2020/03/21.
//
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#define p pair<int,int>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur = 0, idx = 0;

    sort(jobs.begin(), jobs.end());

    priority_queue<p, vector<p >, greater<p>> pq;

    while (!pq.empty() || idx < jobs.size()) {
        if (idx < jobs.size() && jobs[idx][0] <= cur) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
            continue;
        }
        if (!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            cur += a.first;
            answer += cur - a.second;
        } else cur = jobs[idx][0];
    }

    answer /= jobs.size();
    return answer;
}