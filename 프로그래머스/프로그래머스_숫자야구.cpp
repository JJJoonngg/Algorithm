//
// Created by 김종신 on 2020/03/04.
//
#include <string>
#include <vector>

using namespace std;
int tmp, strike, ball, arr[3];

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for (int i = 123; i <= 987; i++) {
        tmp = 0;
        arr[0] = i / 100;
        arr[1] = i / 10 - arr[0] * 10;
        arr[2] = i % 10;
        if (!arr[0] || !arr[1] || !arr[2])continue;
        if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2])continue;
        for (auto cur : baseball) {
            strike = ball = 0;
            string num = to_string(cur[0]);
            for (int j = 0; j < 3; j++) {
                if (arr[j] == num[j] - '0') strike++;
                if (arr[j] == num[(j + 1) % 3] - '0' || arr[j] == num[(j + 2) % 3] - '0') ball++;
            }
            if (cur[1] == strike && cur[2] == ball) tmp++;
        }
        if (tmp == baseball.size()) answer++;
    }
    return answer;
}