//
// Created by 김종신 on 2020/05/11.
//
#include <bits/stdc++.h>

#define MAXI 300001
using namespace std;

int n, q, l, r;
int sum[MAXI], arr[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n + 1);
    sum[1] = arr[1];
    for (int i = 2; i <= n; i++)
        sum[i] += sum[i - 1] + arr[i];

    while (q--) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }
    return 0;
}