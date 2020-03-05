//
// Created by 김종신 on 2020/03/04.
//
#include <vector>
#include <algorithm>

using namespace std;
int one[] = {1, 2, 3, 4, 5};
int two[] = {2, 1, 2, 3, 2, 4, 2, 5};
int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0, idx1 = 0, idx2 = 0, idx3 = 0; i < answers.size(); idx1++, idx2++, idx3++, i++) {
        if (idx1 > 4) idx1 = 0;
        if (idx2 > 7) idx2 = 0;
        if (idx3 > 9) idx3 = 0;
        if (one[idx1] == answers[i]) c1++;
        if (two[idx2] == answers[i]) c2++;
        if (three[idx3] == answers[i])c3++;
    }
    int res = max(c1, max(c2, c3));
    if(c1 == res) answer.push_back(1);
    if(c2 == res) answer.push_back(2);
    if(c3 == res) answer.push_back(3);
    return answer;
}