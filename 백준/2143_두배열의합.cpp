//
// Created by 김종신 on 2020/02/24.
//
#include <bits/stdc++.h>

#define INF LLONG_MAX
#define MAXI 1001
#define ll long long
using namespace std;
long long T, n, m, A[MAXI], B[MAXI], res = 0;
vector<int> x, y;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> T >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> B[i];

    for (int i = 0; i < n; i++) {
        int tmp = A[i];
        x.push_back(tmp);
        for (int j = i + 1; j < n; j++)
            tmp += A[j], x.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp = B[i];
        y.push_back(tmp);
        for (int j = i + 1; j < m; j++)
            tmp += B[j], y.push_back(tmp);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int s = 0, e = y.size() - 1;
    while (true) {
        if (x[s] + y[e] == T) {
            ll i = 1, j = 1;
            while (s + 1 < x.size() && x[s] == x[s + 1]) s++, i++;
            while (e >= 1 && y[e] == y[e - 1]) e--, j++;
            res += i * j;
            e--;
        }
        if (s < x.size() && e >= 0) x[s] + y[e] < T ? s++ : e--;
        if (s >= x.size() || e < 0) break;
    }
    cout << res << "\n";
    return 0;
}