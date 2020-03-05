//
// Created by 김종신 on 2019/12/23.
// Binary Search problem
//
#include <bits/stdc++.h>

#define MAXI 200000 + 1
using namespace std;
int arr[MAXI], n, c, res = 0, dis = 0;;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int _start = 1;
    int _end = arr[n - 1];

    while (_start <= _end) {
        int mid = (_start + _end) / 2;
        int cur = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++)
            if (mid <= arr[i] - arr[cur]) cnt++, cur = i;

        if (cnt >= c) _start = mid + 1, res = mid;
        else _end = mid - 1;
    }
    cout << res << "\n";
    return 0;
}
