//
// Created by 김종신 on 20. 12. 26..
//

#include <bits/stdc++.h>

using namespace std;
int n, input, cnt = 1;
stack<pair<int, int>> s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> input;
        while (!s.empty()) {
            if (input < s.top().second) {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if (s.empty()) {
            cout << "0 ";
        }
        s.push({cnt++, input});
    }
    cout << "\n";
    return 0;
}