//
// Created by 김종신 on 2020/02/07.
//
#include <bits/stdc++.h>

#define MAXI 9
using namespace std;
int N, M, arr[MAXI];
vector<int> v;

void dfs() {
    if (v.size() == M) {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        v.push_back(arr[i]);
        dfs();
        v.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        v.push_back(arr[i]);
        dfs();
        v.pop_back();
    }
    return 0;
}