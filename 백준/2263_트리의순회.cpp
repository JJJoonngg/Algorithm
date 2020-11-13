//
// Created by 김종신 on 2020/11/13.
//
#include <bits/stdc++.h>

#define MAXI 100001
using namespace std;
int n, in[MAXI], post[MAXI], tree[MAXI];

void pre(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd) return;
    if (postStart > postEnd) return;

    int curNode = post[postEnd];
    cout << curNode << " ";

    pre(inStart, tree[curNode] - 1, postStart, postStart + tree[curNode] - inStart - 1);
    pre(tree[curNode] + 1, inEnd, postStart + tree[curNode] - inStart, postEnd - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) tree[in[i]] = i;
    pre(0, n - 1, 0, n - 1);
    cout << "\n";
    return 0;
}