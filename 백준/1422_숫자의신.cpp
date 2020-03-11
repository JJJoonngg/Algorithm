//
// Created by 김종신 on 2020/03/11.
//
#include <bits/stdc++.h>

using namespace std;

bool comp1(string a, string b) {
    if (a.length() != b.length()) return a.length() > b.length();
    else return a > b;
}

bool comp2(string a, string b) {
    return a + b > b + a;
}

int N, K;
string input, res = "";
vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), comp1);
    string E = v[0];
    while (true) {
        if (v.size() == K) break;
        v.push_back(E);
    }
    sort(v.begin(), v.end(), comp2);
    for (auto cur : v)
        res += cur;
    cout << res << "\n";
    return 0;
}