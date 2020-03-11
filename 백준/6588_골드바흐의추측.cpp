//
// Created by 김종신 on 2020/03/06.
//
#include <bits/stdc++.h>

#define MAXI 1000001
using namespace std;
bool arr[MAXI];
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    arr[0] = arr[1] = true;
    for (int i = 2; i < sqrt(MAXI); i++) {
        if (arr[i])continue;
        for (int j = i + i; j < MAXI; j += i)
            arr[j] = true;
    }
    for (int i = 2; i < MAXI; i++)
        if (!arr[i])
            v.push_back(i);


    while (true) {
        cin >> n;
        int tmp = 0;
        if (n == 0) return 0;
        for (int i = 0; i < v.size(); i++) {
            int cur = v[i];
            if (cur > n) break;
            if (!arr[n - cur])
                tmp = cur;
        }
        if (tmp == 0 || tmp == n - tmp) cout << "Goldbach's conjecture is wrong.\n";
        else {
            tmp = n - tmp > 0 ? n - tmp : tmp;
            cout << n << " = " << tmp << " + " << n - tmp << "\n";
        }
    }
    return 0;
}