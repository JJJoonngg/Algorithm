//
// Created by 김종신 on 2020/01/31.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll arr[68];
int t, n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    arr[0] = arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < 68; i++) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
    while (t--) {
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}