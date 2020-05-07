//
// Created by 김종신 on 2020/05/07.
//
#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int tmp = a;
        b = b % 4 + 4;
        for (int i = 2; i <= b; i++)
            a = (tmp * a) % 10;
        if (!a) a = 10;
        cout << a << "\n";
    }
}