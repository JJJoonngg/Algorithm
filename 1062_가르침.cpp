//
// Created by 김종신 on 2020/02/21.
//
#include <bits/stdc++.h>

using namespace std;
vector<string> v;
int n, k, res = 0;
bool alphabet[26], flag;
string input;

int calCnt() {
    int cnt = 0;
    for (auto cur : v) {
        flag = true;
        for (int i = 0; i < cur.length(); i++)
            if (!alphabet[cur[i] - 'a']) {
                flag = false;
                break;
            }
        if (flag) cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt) {
    if (cnt == k) {
        res = max(res, calCnt());
        return;
    }
    for (int i = idx; i < 26; i++)
        if (!alphabet[i]) {
            alphabet[i] = true;
            dfs(i, cnt + 1);
            alphabet[i] = false;
        }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    if (k < 5) {
        cout << "0\n";
        return 0;
    }
    alphabet['a' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    k -= 5;
    dfs(0, 0);
    cout << res << "\n";

    return 0;
}