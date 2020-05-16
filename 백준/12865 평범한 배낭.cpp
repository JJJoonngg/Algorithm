//
// Created by 김종신 on 2020/05/16.
//
#include <bits/stdc++.h>

#define MAXI 101
using namespace std;
int n, k, a, b;
int arr[MAXI][100000 + 1];
struct info {
    int w, v;
};
vector<info> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n >> k;
    v.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 1) {
                if (v[i].w <= j) arr[i][j] = v[i].v;
                continue;
            }
            if (v[i].w <= j) arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - v[i].w] + v[i].v);
            else arr[i][j] = arr[i - 1][j];
        }
    }
    cout << arr[n][k] << "\n";

    return 0;
}