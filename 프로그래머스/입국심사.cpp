//
// Created by 김종신 on 2020/04/04.
//
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

long long solution(int n, vector<int> times) {
    ll answer, s = 0, e = 0, m;
    for (long long a : times)
        e = max(e, a);
    e *= n;
    answer = e;
    while (s <= e) {
        ll tmp = 0;
        m = (s + e) / 2;
        for (long long a : times)
            tmp += m / a;

        if (tmp < n) s = m + 1;
        else {
            answer = min(answer, m);
            e = m - 1;
        }
    }

    return answer;
}