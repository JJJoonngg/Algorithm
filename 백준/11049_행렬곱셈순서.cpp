//
// Created by 김종신 on 2020/01/29.
//
#include <bits/stdc++.h>

#define ll long long
#define MAXI 500 + 1
#define INF 1e9
using namespace std;
ll m[MAXI][MAXI];
int N, R, C, p[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> R >> C;
        p[i] = R;
        if (i == N - 1) p[i + 1] = C;
    }
    for (int i = 1; i <= N; i++) m[i][i] = 0;
    for (int l = 2; l <= N; l++) {
        for (int i = 1; i <= N - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++) {
                ll q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                m[i][j] = min(q, m[i][j]);
            }
        }
    }
    cout << m[1][N] << "\n";
    return 0;
}
