//
// Created by 김종신 on 2020/03/04.
//
#include <bits/stdc++.h>

#define MAXI 51
using namespace std;
int arr[MAXI][10], N, res;
bool check[10], ground[3];
vector<int> v;

int run(int cur) {
    int score = 0;
    for (int i = 2; i >= 0; i--) {
        if (ground[i]) {
            if (cur + i >= 3) score++;
            else ground[cur + i] = true;
            ground[i] = false;
        }
    }
    if (cur == 4) score++;
    else ground[cur - 1] = true;
    return score;
}

void func() {
    int outCnt, cur = 1, tmp = 0;
    for (int i = 1; i <= N; i++) {
        outCnt = 0;
        memset(ground, false, sizeof(ground));
        while (true) {
            if (cur > 9)cur = 1;
            if (!arr[i][v[cur]]) {
                outCnt++;
                if (outCnt == 3) {
                    cur++;
                    break;
                }
            } else
                tmp += run(arr[i][v[cur]]);
            cur++;
        }
    }
    res = max(tmp, res);
}

void dfs() {
    if (v.size() == 9) {
        v.insert(v.begin() + 4, 1);
        func();
        v.erase(v.begin() + 4);
        return;
    }
    for (int i = 2; i < 10; i++) {
        if (!check[i]) {
            check[i] = true;
            v.push_back(i);
            dfs();
            v.pop_back();
            check[i] = false;
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < 10; j++)
            cin >> arr[i][j];
    v.push_back(0);
    dfs();
    cout << res << "\n";
    return 0;
}