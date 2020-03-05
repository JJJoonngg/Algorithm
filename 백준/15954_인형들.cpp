//
// Created by 김종신 on 2020/02/26.
//
//자료형 캐스팅, 오차 범위 떄문에 6번 틀렸던 문제
//
#include <bits/stdc++.h>

#define ld  long double
#define INF LDBL_MAX
#define MAXI 501
using namespace std;
ld arr[MAXI], res = INF, N, K, i, j;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (i = 0; i < N - K + 1; i++) {
        for (j = K; j < N - i + 1; j++) {
            ld M = 0, V = 0;
            for (int x = i; x < i + j; x++) M += arr[x];
            M /= (ld) j;
            for (int x = i; x < i + j; x++) V += pow((arr[x] - M), 2);
            V /= (ld) j;
            res = min(res, sqrt(V));
        }
    }
    cout << fixed << setprecision(11) << res << "\n";
    return 0;
}