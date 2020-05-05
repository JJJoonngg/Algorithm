//
// Created by 김종신 on 2020/04/04.
//
#include <vector>

#define INF 101
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<int> node[INF];
    vector<int> endNode;
    vector<int> inEdge(n + 1, 0);
    vector<int> outEdge(n + 1, 0);

    for (auto cur : results) {
        node[cur[0]].push_back(cur[1]);
        inEdge[cur[1]]++;
        outEdge[cur[0]]++;
    }

    return answer;
}
