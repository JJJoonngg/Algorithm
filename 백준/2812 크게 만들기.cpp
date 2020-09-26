//
// Created by 김종신 on 2020/09/26.
//
#include <bits/stdc++.h>

using namespace std;
int n, k;
string input;
deque<char> dq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> k >> input;

    for (auto a : input) {
        while (k && !dq.empty() && dq.back() < a)
            dq.pop_back(), k--;

        dq.push_back(a);
    }

    for (int i = 0; i < dq.size() - k; i++)
        cout << dq[i];
    cout << "\n";
    return 0;
}