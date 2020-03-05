//
// Created by 김종신 on 2020/02/03.
//
#include <bits/stdc++.h>

#define MAXI 51
using namespace std;
struct info {
    int idx, val, res;
};
info A[MAXI];
int N;

bool compValue(info x, info y) {
    return x.val != y.val ? x.val < y.val : x.idx < y.idx;
}

bool compIndex(info x, info y) {
    return x.idx < y.idx;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].val;
        A[i].idx = i;
    }
    sort(A, A + N, compValue);
    for (int i = 0; i < N; i++) A[i].res = i;
    sort(A, A + N, compIndex);
    for (int i = 0; i < N; i++) cout << A[i].res << " ";
    cout << "\n";
    return 0;
}