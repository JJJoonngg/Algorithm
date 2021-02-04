//
// Created by 김종신 on 21. 2. 4..
//

#include <bits/stdc++.h>

using namespace std;

int n, res = 0, alphabet[26];
vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        v.push_back(input);
    }

    for (int i = 0; i < v.size(); i++) {
        int decimal = 1;
        for (int j = v[i].size() - 1; j >= 0; j--) {
            alphabet[v[i][j] - 'A'] += decimal, decimal *= 10;
        }
    }
    sort(alphabet, alphabet + 26);
    int temp = 9;
    for (int i = 25; i >= 0; i--) {
        if (!alphabet[i])break;
        res += alphabet[i] * temp;
        temp--;
    }
    cout << res << "\n";
    return 0;
}