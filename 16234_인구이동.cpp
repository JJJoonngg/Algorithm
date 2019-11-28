//
// Created by 김종신 on 18/10/2019.
//
//https://www.acmicpc.net/problem/16234
//input
//2 20 50
//50 30
//20 40
//
//2 40 50
//50 30
//20 40
//
//2 20 50
//50 30
//30 40
//output
//1
//0
//1
#include <bits/stdc++.h>

#define MAXI 50 + 1
using namespace std;
int arr[MAXI][MAXI] = {0,};
int N, L, R;

bool checkRange(int x, int y) { return y >= 0 && y < N && x >= 0 && x < N; }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    return 0;
}