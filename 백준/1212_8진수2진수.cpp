//
// Created by 김종신 on 2020/01/27.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    string input;
    cin >> input;
    if(input == "0"){
        cout << 0<<"\n";
        return 0;
    }
    int tmp = int(input[0] - '0');
    string output = "";
    while (tmp > 0) {
        output += to_string(tmp % 2);
        tmp /= 2;
    }
    reverse(output.begin(), output.end());
    cout << output;
    for (int i = 1; i < input.size(); i++) {
        tmp = int(input[i] - '0');
        output = "";
        while (tmp > 0) {
            output += to_string(tmp % 2);
            tmp /= 2;
        }
        while (output.size() != 3) output += to_string(0);
        reverse(output.begin(), output.end());
        cout << output;
    }
    cout << "\n";
    return 0;
}