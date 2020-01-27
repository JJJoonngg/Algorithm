//
// Created by 김종신 on 2020/01/27.
//
#include <bits/stdc++.h>

using namespace std;
string input, output = "";

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> input;
    reverse(input.begin(), input.end());
    while(input.size()%3 != 0){
        input += "0";
    }
    for (int i = 0; i < input.size(); i += 3) {
        int tmp = 1, res = 0;
        for (int cnt = 0; cnt < 3; cnt++) {
            int cur = int(input[i + cnt] - '0');
            cur *= tmp;
            res += cur;
            tmp *= 2;
        }
        output += to_string(res);
    }
    reverse(output.begin(),output.end());
    cout << output<<"\n";
    return 0;
}