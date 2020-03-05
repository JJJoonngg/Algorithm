//
// Created by 김종신 on 2020/02/20.
//
#include <bits/stdc++.h>

using namespace std;
int arr1[4], res = 0, arr2[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    for (int i = 1; i <= 3; i++) cin >> arr1[i];
    for (int i = 1; i <= 3; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++) arr2[j]++;
    }
    for (int i = 0; i < 100; i++)
        res += arr2[i] * arr1[arr2[i]];
    cout << res << "\n";
    return 0;
}