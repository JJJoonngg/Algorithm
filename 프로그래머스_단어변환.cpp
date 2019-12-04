//
// Created by 김종신 on 24/10/2019.
//
#include <bits/stdc++.h>
using namespace std;
bool flag = false;

int dfs(int cnt, string cur, string res, vector<string> &v){
    if(cur == res){
        flag = true;
        return cnt;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int cnt = 0;


    answer = min(answer, cnt);
    if(!flag) answer = 0;
    return answer;
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    vector<string> v;
    v.push_back("hot");
    v.push_back("dot");
    v.push_back("dog");
    v.push_back("lot");
    v.push_back("log");
    v.push_back("cog");
    return 0;
}