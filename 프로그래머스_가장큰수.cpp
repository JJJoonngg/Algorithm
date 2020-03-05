//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string x, string y) {
    return x + y > y + x;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (auto cur : numbers)
        v.push_back(to_string(cur));

    sort(v.begin(), v.end(), comp);
    for (auto cur : v)
        answer += cur;
    if (v[0] == "0")
        answer = "0";

    return answer;
}