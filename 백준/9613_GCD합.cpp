//
// Created by 김종신 on 2020/03/06.
//
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t, n, arr[101];
    cin >> t;
    while (t--) {
        cin >> n;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                res += gcd(arr[i], arr[j]);
        cout << res << "\n";
    }
    return 0;
}