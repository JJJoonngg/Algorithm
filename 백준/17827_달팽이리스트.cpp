//
// Created by 김종신 on 2020/02/24.
//
#include <bits/stdc++.h>

#define MAXI 200001
using namespace std;
int n, m, v, mod, input, i;
vector<int> arr;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> v;
    for (i = 1; i <= n; i++) {
        cin >> input;
        arr.push_back(input);
    }
    mod = n - v + 1;
    for (i = 1; i <= m; i++) {
        cin >> input;
        if (input < n) {
            cout << arr[input] << "\n";
        } else {
            if (v == n) {
                cout << arr[n - 1] << "\n";
                continue;
            }
            while (true) {
                input -= mod;
                if (input < n) break;
                input += v + 1;
            }
            cout << arr[input] << "\n";
        }
    }
    return 0;
}