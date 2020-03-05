//
// Created by 김종신 on 2019/11/24.
//
#include <bits/stdc++.h>

#define MAXI 21
#define INF 1e9
using namespace std;
int arr[MAXI][MAXI], n;
int res = INF;
bool check[MAXI];

void dfs(int cur, int cnt) {
    if(cnt == n/2){
        int sum1 = 0, sum2 = 0;
        for(int i=1;i<=n;i++){
            if(check[i]) continue;
            for(int j=i+1;j<=n;j++){
                if(check[j]) continue;
                sum1+= arr[i][j] + arr[j][i];
            }
        }
        for(int i=1;i<=n;i++) {
            if (!check[i]) continue;
            for (int j = i+1; j <= n; j++) {
                if (!check[j]) continue;
                sum2 += arr[i][j] + arr[j][i];
            }
        }
        res = min(res, abs(sum1 - sum2));
        return;
    }
    for(int i = cur+1; i <=n;i++){
        if(!check[i]){
            check[i] = true;
            dfs(i, cnt+1);
            check[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    dfs(0, 0);

    cout << res<<"\n";

    return 0;
}