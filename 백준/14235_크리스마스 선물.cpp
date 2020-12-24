//
// Created by 김종신 on 20. 12. 24..
//

#include <bits/stdc++.h>

using namespace std;
int n, a, input;
priority_queue<int> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << "-1\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            for (int i = 0; i < a; i++) {
                cin >> input;
                pq.push(input);
            }
        }
    }
    return 0;
}