//
// Created by 김종신 on 2020/10/24.
//
#include <bits/stdc++.h>

using namespace std;
struct info {
    int a, b;
} arr[21];
int len, wid, hei, n, res = 0;
bool flag;

bool comp(info x, info y) { return x.a > y.a ? true : false; }

void func(int l, int w, int h) {
    if (flag || (!l || !w || !h)) return;
    for (int i = 0; i < n; i++) {
        if (l >= arr[i].a && w >= arr[i].a
            && h >= arr[i].a && arr[i].b > 0) {
            arr[i].b--, res++;
            func(l - arr[i].a, w, arr[i].a);
            func(arr[i].a, w - arr[i].a, arr[i].a);
            func(l, w, h - arr[i].a);
            return;
        }
    }
    flag = true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> len >> wid >> hei >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].a = pow(2, arr[i].a);
    }
    sort(arr, arr + n, comp);
    func(len, wid, hei);
    flag ? cout << "-1\n" : cout << res << "\n";
    return 0;
}