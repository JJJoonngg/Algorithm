//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> tmp;
        for (int a = commands[i][0] - 1; a < commands[i][1]; a++) {
            tmp.push_back(array[a]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}