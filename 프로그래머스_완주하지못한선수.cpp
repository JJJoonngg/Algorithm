//
// Created by 김종신 on 2020/03/04.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    map<string, int> m;
    for (int i = 0; i < participant.size(); i++) {
        if (m.find(participant[i]) == m.end()) {
            m.insert({participant[i], 1});
        } else m.find(participant[i])->second++;
    }
    for (int i = 0; i < completion.size(); i++) {
        if (m.find(completion[i]) != m.end()) {
            m.find(completion[i])->second--;
            if (m.find(completion[i])->second == 0) {
                m.erase(m.find(completion[i]));
            }
        }
    }
    string answer = "";
    answer += m.begin()->first;
    return answer;
}

int main() {
    vector<string> p;
    p.push_back("mislav");
    p.push_back("mislav");
    p.push_back("stanko");
    p.push_back("ana");

    vector<string> c;
    c.push_back("stanko");
    c.push_back("ana");
    c.push_back("mislav");

    cout << solution(p, c) << "\n";
}