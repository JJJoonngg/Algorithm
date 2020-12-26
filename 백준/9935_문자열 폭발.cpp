//
// Created by 김종신 on 20. 12. 26..
//

#include <bits/stdc++.h>

using namespace std;

string input, boom, res = "";
int inputSize, boomSize;
bool flag;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> input >> boom;
    inputSize = input.length(), boomSize = boom.length();

    for (int i = 0; i < inputSize; i++) {
        res += input[i];
        if (input[i] == boom[boomSize - 1] && i >= boomSize - 1) {
            flag = true;
            for (int j = 1; j < boomSize; j++)
                if (res[res.length() - 1 - j] != boom[boomSize - 1 - j])
                    flag = false;

            if (flag)
                for (int j = 0; j < boomSize; j++)
                    res.pop_back();
        }
    }
    res = !res.empty() ? res : "FRULA";
    cout << res << "\n";

    return 0;
}