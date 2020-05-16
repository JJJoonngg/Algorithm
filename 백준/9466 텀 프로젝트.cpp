//
// Created by 김종신 on 2020/05/16.
//
#include <bits/stdc++.h>

#define MAXI 100000 + 1
using namespace std;
int t, n, res, arr[MAXI], visit[MAXI], check[MAXI];

void dfs(int cur) {
    visit[cur] = true;
    if (!visit[arr[cur]]) dfs(arr[cur]);
    else if (!check[arr[cur]]) {
        for (int i = arr[cur]; i != cur; i = arr[i]) res++;
        res++;
    }
    check[cur] = true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        res = 0;
        memset(arr, 0, sizeof(arr));
        memset(visit, 0, sizeof(visit));
        memset(check, 0, sizeof(check));

        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) if (!visit[i]) dfs(i);

        cout << n - res << "\n";
    }
    return 0;
}