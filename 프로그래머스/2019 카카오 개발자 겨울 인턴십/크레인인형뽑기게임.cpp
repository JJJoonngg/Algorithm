//
// Created by 김종신 on 2020/05/05.
//
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    deque<int> dq[31];

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[j][i] == 0) continue;
            dq[i].push_back(board[j][i]);
        }
    }

    stack<int> s;

    for (auto a : moves) {
        int pos = a - 1;
        if (dq[pos].empty()) continue;
        int cur = dq[pos].front();
        dq[pos].pop_front();
        if (!s.empty()) {
            if (s.top() == cur) {
                s.pop();
                answer += 2;
            } else {
                s.push(cur);
            }
        }else s.push(cur);
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    vector<vector<int>> a;
    vector<int> b;

    vector<int> tmp;

    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    a.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(3);
    a.push_back(tmp);
    tmp.clear();

    tmp.push_back(0);
    tmp.push_back(2);
    tmp.push_back(5);
    tmp.push_back(0);
    tmp.push_back(1);
    a.push_back(tmp);
    tmp.clear();

    tmp.push_back(4);
    tmp.push_back(2);
    tmp.push_back(4);
    tmp.push_back(4);
    tmp.push_back(2);
    a.push_back(tmp);
    tmp.clear();

    tmp.push_back(3);
    tmp.push_back(5);
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(1);
    a.push_back(tmp);
    tmp.clear();

    b.push_back(1);
    b.push_back(5);
    b.push_back(3);
    b.push_back(5);
    b.push_back(1);
    b.push_back(2);
    b.push_back(1);
    b.push_back(4);

    cout << solution(a, b) << "\n";
    return 0;
}