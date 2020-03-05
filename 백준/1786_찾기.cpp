//
// Created by 김종신 on 2020/02/16.
//
#include <bits/stdc++.h>

using namespace std;
string input, p;

vector<int> getPi(string s) {
    int siz = s.length(), j = 0;
    vector<int> v(siz, 0);
    for (int i = 1; i < siz; i++) {
        while (j > 0 && s[i] != s[j]) j = v[j - 1];
        if (s[i] == s[j]) v[i] = ++j;
    }
    return v;
}

vector<int> kmp(string origin, string pattern) {
    vector<int> res;
    auto pi = getPi(pattern);
    int j = 0;
    for (int i = 0; i < origin.length(); i++) {
        while (j > 0 && origin[i] != pattern[j]) j = pi[j - 1];
        if (origin[i] == pattern[j]) {
            if (j == pattern.length() - 1) {
                res.push_back(i - pattern.length() + 1);
                j = pi[j];
            } else j++;
        }
    }
    return res;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    getline(cin, input);
    getline(cin, p);
    auto res = kmp(input, p);
    cout << res.size() << "\n";
    for (auto cur : res) cout << cur + 1 << " ";
    cout << "\n";
    return 0;
}