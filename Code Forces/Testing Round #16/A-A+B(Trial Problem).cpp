//
// Created by 김종신 on 2020/05/07.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}