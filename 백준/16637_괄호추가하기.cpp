//
// Created by 김종신 on 2020/02/08.
//
#include <bits/stdc++.h>

#define MAXI 20
#define INF 1e9
#define ll long long
using namespace std;
ll n, res;
string input;
vector<ll> num;
vector<char> op;

ll calculate(ll x, ll y, char op) {
    if (op == '+') return x + y;
    else if (op == '-') return x - y;
    else if (op == '*') return x * y;
}

void dfs(ll cur, int idx) {
    if (op.size() <= idx) {
        res = max(cur, res);
        return;
    }
    ll tmp = calculate(cur, num[idx + 1], op[idx]);
    dfs(tmp, idx + 1);
    if (idx + 1 < op.size()) {

        tmp = calculate(num[idx + 1], num[idx + 2], op[idx + 1]);
        dfs(calculate(cur, tmp, op[idx]), idx + 2);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            op.push_back(input[i]);
        else num.push_back(input[i] - '0');
    }
    res = -1 * INF;
    dfs(num[0], 0);
    cout << res << "\n";
    return 0;
}