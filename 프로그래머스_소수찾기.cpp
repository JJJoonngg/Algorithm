//
// Created by 김종신 on 2020/03/04.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
int cnt[10] = {0,}, siz = 0, answer = 0;

bool prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return false;
    return true;
}

bool check() {
    for (int i = 0; i < 10; i++)
        if (cnt[i]) return false;
    return true;
}

void dfs(string s) {
    if (s[0] == '0') return;
    int cur = atoi(s.c_str());
    if (prime(cur) && cur > 1)
        answer++;
    if (check()) return;
    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            cnt[i]--;
            dfs(s + to_string(i));
            cnt[i]++;
        }
    }
}

int solution(string numbers) {
    siz = numbers.length();
    for (int i = 0; i < siz; i++)
        cnt[numbers[i] - '0']++;

    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            cnt[i]--;
            dfs(to_string(i));
            cnt[i]++;
        }
    }
    return answer;
}

int main() {
    solution("011");
    return 0;
}