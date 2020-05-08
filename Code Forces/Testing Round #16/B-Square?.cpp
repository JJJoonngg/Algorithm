//
// Created by 김종신 on 2020/05/07.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t, a1, b1, a2, b2;
    cin >> t;
    while (t--) {
        cin >> a1 >> b1 >> a2 >> b2;
        if (a1 > b1) swap(a1, b1);
        if (a2 > b2) swap(a2, b2);
        if (b1 == b2 && a1 + a2 == b1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}