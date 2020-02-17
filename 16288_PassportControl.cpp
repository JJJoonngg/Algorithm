//
// Created by 김종신 on 2020/02/17.
//
#include <bits/stdc++.h>

using namespace std;
int n, k, input, j;
int arr[101];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> input;
        for (j = 0; j < k; j++) {
            if (input > arr[j]) {
                arr[j] = input;
                break;
            }
        }
        if (j == k) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}