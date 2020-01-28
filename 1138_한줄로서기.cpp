//
// Created by 김종신 on 2020/01/28.
//
#include <bits/stdc++.h>

#define MAXI 11
using namespace std;
int N, arr[MAXI];
vector<int> res;

bool checkStatus() {
    for (int i = 1; i <= N; i++) {
        int count1 = arr[i], count2 = 0;
        for (int j = 0; j < N; j++) {
            if (res[j] == i) break;
            if (res[j] > i) count2++;
        }
        if (count1 != count2) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        res.push_back(i);
    }
    do {
        if (checkStatus()) break;
    } while (next_permutation(res.begin(), res.end()));
    for (int i = 0; i < N; i++) cout << res[i] << " ";
    cout << "\n";
    return 0;
}
