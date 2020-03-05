//
// Created by 김종신 on 2020/01/30.
//
#include <bits/stdc++.h>

#define MAXI 15
#define none '!'
using namespace std;
char arr[MAXI][MAXI];
string input, output = "";

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < MAXI; i++) for (int j = 0; j < MAXI; j++) arr[i][j] = none;
    for (int i = 0; i < 5; i++) {
        cin >> input;
        for (int j = 0; j < input.size(); j++)
            arr[i][j] = input[j];
    }
    for (int i = 0; i < MAXI; i++) {
        for (int j = 0; j < MAXI; j++) {
            if (arr[j][i] == none) continue;
            output += arr[j][i];
        }
    }
    cout << output << "\n";
    return 0;
}