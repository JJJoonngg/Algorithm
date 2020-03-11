//
// Created by 김종신 on 2020/03/06.
//
#include <bits/stdc++.h>

#define MAXI 1000001
#define mod 1000000009
using namespace std;

long long arr[MAXI], T, n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < MAXI; i++)
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % mod;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}