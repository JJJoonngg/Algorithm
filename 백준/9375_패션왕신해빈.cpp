//
// Created by 김종신 on 2020/02/23.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, string>> v;
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            bool flag = false;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].second == type) {
                    v[j].first++;
                    flag = true;
                    break;
                }
            }
            if (!flag) v.push_back({1, type});
        }
        int res = 1;
        for (int i = 0; i < v.size(); i++) {
            res *= (v[i].first + 1);
        }
        cout << res - 1 << "\n";
    }
    return 0;
}