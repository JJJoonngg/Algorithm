//
// Created by 김종신 on 2020/02/16.
//
//KMP 참조 : https://bowbowbow.tistory.com/6
#include <bits/stdc++.h>

using namespace std;
int l;
string input;

vector<int> getPi(string s) {
    int siz = s.length(), j = 0;
    vector<int> v(siz, 0);
    for (int i = 1; i < siz; i++) {
        while (j > 0 && s[i] != s[j]) j = v[j - 1];
        if (s[i] == s[j]) v[i] = ++j;
    }
    return v;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> l >> input;
    vector<int> v = getPi(input);
    cout << input.length() - v[l - 1] << "\n";

    return 0;
}