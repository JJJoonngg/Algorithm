//
// Created by 김종신 on 2020/02/25.
//
//참고
//https://m.blog.naver.com/PostView.nhn?blogId=whgksdyd112&logNo=220944737243&proxyReferer=https%3A%2F%2Fwww.google.com%2F
//
#include <bits/stdc++.h>

#define MAXI 33000
using namespace std;
int n;

void preorder(int cur, int level) {
    if (level == 1) {
        cout << cur << " ";
        return;
    }
    int s = (1 << n) - (1 << (n - level + 1));
    int e = (1 << (n - level));
    cout << s + e - cur + 1 << " ";
    preorder(cur, level - 1);
    preorder(cur + e, level - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    preorder(1, n);
    return 0;
}