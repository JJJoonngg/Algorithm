//
// Created by 김종신 on 2020/03/12.
//
#include <bits/stdc++.h>

#define p pair<int, int>
using namespace std;
int N, input, res = 0;
vector<p > v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(make_pair(input, i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        if (res < (v[i].second - i))
            res = v[i].second - i;
    cout << res + 1 << "\n";
    return 0;
}