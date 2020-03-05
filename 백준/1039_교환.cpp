//
// Created by 김종신 on 2020/02/04.
//
#include <bits/stdc++.h>

#define MAXI 1000001
using namespace std;
int K, res = 0, num[11][MAXI];
string N;

int dfs(string input, int cnt) {
    if (cnt == K) return stoi(input);
    int &cur = num[cnt][stoi(input)];
    if (cur != -1) return cur;
    for (int i = 0; i < input.length() - 1; i++) {
        for (int j = i + 1; j < input.length(); j++) {
            swap(input[i], input[j]);
            if (input[0] == '0') {
                swap(input[i], input[j]);
                continue;
            }
            cur = max(cur, dfs(input, cnt + 1));
            swap(input[i], input[j]);
        }
    }
    return cur;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < MAXI; j++)
            num[i][j] = -1;
    cout << dfs(N, 0) << "\n";
    return 0;
}