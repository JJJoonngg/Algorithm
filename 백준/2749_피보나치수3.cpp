//
// Created by 김종신 on 20. 12. 5..
//

#include <bits/stdc++.h>

#define ll long long
#define mod 1000000
#define cycle 1500000
using namespace std;

int arr[cycle];
ll n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    arr[0] = 0, arr[1] = 1;
    cin >> n;
    for (int i = 2; i < cycle; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] %= mod;
    }
    cout << arr[n % cycle] << "\n";
    return 0;
}