//
// Created by 김종신 on 2020/05/06.
//
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int len = s.length(), answer = 10001;
    if (len == 1) return 1;
    for (int i = 1; i <= len / 2; i++) {
        int len2 = len;
        for (int j = 0; j < len; j++) {
            int cnt = 0;
            for (int k = i; j + k < len; k += i) {
                if (s.substr(j, i) == s.substr(j + k, i)) cnt++;
                else {
                    len2 -= i * cnt;
                    if (cnt != 0) len2 += to_string(cnt + 1).length();
                    j += k - 1;
                    break;
                }
                if (i + j + k >= len) {
                    len2 = len2 - (i * cnt) + to_string(cnt + 1).length();
                    j += k;
                }
            }
        }
        answer = min(len2, answer);
    }
    return answer;
}