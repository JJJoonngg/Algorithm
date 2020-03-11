//
// Created by 김종신 on 2020/03/12.
//
#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else {
        int A = 0, B = 0;
        for (int i = 0; i < a.length(); i++) {
            if ('0' <= a[i] && a[i] <= '9')
                A += a[i] - '0';
            if ('0' <= b[i] && b[i] <= '9')
                B += b[i] - '0';
        }
        if (A != B) return A < B;
        else return a < b;
    }
}

vector<string> v;
int N;
string input;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), comp);
    for (auto a :v)
        cout << a << "\n";
    return 0;
}