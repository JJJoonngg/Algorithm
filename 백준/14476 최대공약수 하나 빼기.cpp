//
// Created by 김종신 on 2020/05/15.
//
#include <bits/stdc++.h>

#define MAXI 1000000 + 1
using namespace std;
int arr[MAXI], n, i, cur, resGCD, resIDX, s[MAXI], e[MAXI];

int gcd(int a, int b) {
    int tmp, tmpA = a, tmpB = b;
    if (tmpA < tmpB) swap(tmpA, tmpB);
    while (tmpB != 0) {
        tmp = tmpA % tmpB;
        tmpA = tmpB;
        tmpB = tmp;
    }
    return tmpA;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (i = 0; i < n; i++) cin >> arr[i];

    s[0] = arr[0], e[n - 1] = arr[n - 1];
    for (i = 1; i < n; i++) {
        s[i] = gcd(arr[i], s[i - 1]);
        e[n - 1 - i] = gcd(arr[n - 1 - i], e[n - i]);
    }

    cur = e[1];
    if (cur > arr[0] || gcd(cur, arr[0]) != cur) resGCD = cur;

    for (i = 1; i < n - 1; i++) {
        cur = gcd(s[i - 1], e[i + 1]);
        if (cur > arr[i] || gcd(cur, arr[i]) != cur)
            if (resGCD < cur) resGCD = cur, resIDX = i;
    }

    if (arr[n - 1] < s[n - 2] || gcd(arr[n - 1], s[n - 2]) != cur)
        if (resGCD < cur) resGCD = cur, resIDX = n - 2;

    if (resGCD == 0) cout << "-1";
    else cout << resGCD << " " << arr[resIDX] << "\n";

    return 0;
}