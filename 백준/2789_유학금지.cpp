//
// Created by 김종신 on 2020/01/30.
//

#include <bits/stdc++.h>

using namespace std;
string s = "CAMBRIDGE";
string input, output = "";

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        char cur = input[i];
        bool flag = true;
        for (int j = 0; j < s.size(); j++) {
            if (cur == s[j]) {
                flag = false;
                break;
            }
        }
        if (flag) output += cur;
    }
    cout << output << "\n";

    return 0;
}