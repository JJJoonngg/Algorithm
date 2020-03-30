//
// Created by 김종신 on 2020/03/30.
//
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> dq;
    for(auto cur : operations){
        if(!cur.compare("D 1")){
            if(!dq.empty()) dq.pop_back();
        }
        else if(!cur.compare("D -1")){
            if(!dq.empty()) dq.pop_front();
        }else{
            dq.push_back(stoi(cur.substr(2)));
            sort(dq.begin(), dq.end());
        }
    }
    vector<int> answer;
    if(!dq.empty()){
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}