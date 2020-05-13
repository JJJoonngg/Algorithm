//
// Created by 김종신 on 2020/05/13.
//
#include <bits/stdc++.h>

#define INF 2e9
#define MAXI 101
using namespace std;

int v, m, a, b, J, S;
long long c, arr[MAXI][MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> v >> m;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            arr[i][j] = i == j ? 0 : INF;
    while (m--) {
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
        arr[b][a] = arr[a][b];
    }

    cin >> J >> S;

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];

    long long res = -1, tmp = INF, tmp2 = INF;

    for (int i = 1; i <= v; i++) {
        if (i == J || i == S) continue;
        if (arr[J][i] == INF || arr[i][S] == INF) continue;
        tmp = min(tmp, arr[J][i] + arr[i][S]);
    }
    for (int i = 1; i <= v; i++) {
        if (i == J || i == S) continue;
        if (arr[J][i] == INF || arr[i][S] == INF) continue;
        if (tmp < arr[J][i] + arr[i][S]) continue;
        if (arr[J][i] > arr[i][S]) continue;
        if (tmp2 > arr[J][i])
            res = i, tmp2 = arr[J][i];
    }

    cout << res << "\n";

    return 0;
}