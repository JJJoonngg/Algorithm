//
// Created by 김종신 on 2020/02/17.
//
#include <bits/stdc++.h>

#define MAXI 800000
using namespace std;
int n, w, arr[5001];
bool weight[MAXI];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] > w) break;
            if (weight[w - arr[i] - arr[j]]) {
                cout << "YES\n";
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
            if (arr[i] + arr[j] < w)
                weight[arr[i] + arr[j]] = true;
    }
    cout << "NO\n";
    return 0;
}