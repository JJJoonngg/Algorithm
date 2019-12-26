//
// Created by 김종신 on 2019/12/24.
// Bruth Force & GCD problem
// using extended_euclidean algorithm
//
#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> v;
vector<int> res;

tuple<int, int, int> extended_euclidean(int a, int b) {
    if (b == 0) return make_tuple(a, 1, 0);
    int gcd, x, y;
    tie(gcd, x, y) = extended_euclidean(b, a % b);
    return make_tuple(gcd, y, x - (a / b) * y);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int m = v[1] - v[0];

    tuple<int, int, int> gcd;
    for (int i = 2; i < N; i++) {
        gcd = extended_euclidean(m, v[i] - v[i - 1]);
        m = get<0>(gcd);
    }

    for (int i = 1; i <= sqrt(m); i++) {
        if (m % i == 0) {
            res.push_back(i);
            if (i != m / i) res.push_back(m / i);
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (res[i] != 1)
            cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}

