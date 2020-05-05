//
// Created by 김종신 on 2020/04/04.
//
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    for (int i = 1; i * i <= red; i++) {
        if (red % i == 0) {
            int x = red / i, y = i;
            if (2 * x + 2 * y + 4 == brown) {
                answer.push_back(x + 2);
                answer.push_back(y + 2);
                break;
            }
        }
    }

    return answer;
}