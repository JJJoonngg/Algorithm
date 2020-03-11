//
// Created by 김종신 on 2020/03/11.
//
#include <bits/stdc++.h>

#define ll long long
#define p pair<ll, int>
using namespace std;

bool comp(p a, p b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

ll N, res, input;
map<ll, int> m;
vector<p > v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (m.find(input) == m.end())
            m.insert(make_pair(input, 1));
        else m.find(input)->second++;
    }

    for (auto cur :m)
        v.push_back(cur);

    sort(v.begin(), v.end(), comp);
    cout << v[0].first << "\n";

    return 0;
}