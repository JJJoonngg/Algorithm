//
// Created by 김종신 on 2020/02/03.
//
#include <bits/stdc++.h>

#define count 26
using namespace std;
string input, output = "", tmp;
int alphabet[count], odd = 0;
char oddAlphabet;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> input;
    for (int i = 0; i < input.length(); i++)
        alphabet[input[i] - 'A']++;
    for (int i = 0; i < count; i++) {
        if (alphabet[i] % 2 == 1) {
            odd++;
            oddAlphabet = i + 'A';
        }
    }
    if (odd >= 2) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0)continue;
        for (int j = 0; j < alphabet[i] / 2; j++)
            output += char(i + 'A');
    }
    tmp = output;
    reverse(tmp.begin(), tmp.end());
    if (odd != 0) output += oddAlphabet;
    cout << output + tmp << "\n";

    return 0;
}