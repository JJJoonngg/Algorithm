//
// Created by 김종신 on 2020/05/08.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    while (true) {
        string input;
        cin >> input;
        if (input == "0") return 0;
        string reverseInput = input;
        reverse(reverseInput.begin(), reverseInput.end());
        if (input == reverseInput) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}