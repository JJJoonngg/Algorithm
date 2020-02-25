//
// Created by 김종신 on 2020/02/24.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    map<string, string> m;
    int N, M;
    cin >> N >> M;
    while (N--) {
        string site, pwd;
        cin >> site >> pwd;
        m.insert({site, pwd});
    }
    while (M--) {
        string site;
        cin >> site;
        cout << m.find(site)->second << "\n";
    }
    return 0;
}