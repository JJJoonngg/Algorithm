//
// Created by 김종신 on 2020/03/21.
//
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXI 102
using namespace std;

int a[MAXI][MAXI], b[MAXI][MAXI], c[MAXI][MAXI];

bool comp(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[0] == b[0] && a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

bool judge(int x, int y, int z) {
    if (!z) {
        if (y == 0 || (y >= 1 && a[y - 1][x]) || b[y][x] || (x >= 1 && b[y][x - 1])) return true;
        return false;
    } else {
        if ((y >= 1 && (a[y - 1][x] || a[y - 1][x + 1])) || (x >= 1 && (b[y][x - 1] && b[y][x + 1]))) return true;
        return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

    for (auto cur : build_frame) {
        int x = cur[0], y = cur[1], z = cur[2], build = cur[3];
        if (build) {
            if (!z) {
                if (judge(x, y, z)) {
                    c[y][x] += 1;
                    a[y][x] = 1;
                }
            } else {
                if (judge(x, y, z)) {
                    c[y][x] += 2;
                    b[y][x] = 1;
                }
            }
        } else {
            if (!z) {
                a[y][x] = 0;
                if (a[y + 1][x] && !judge(x, y + 1, 0)) a[y][x] = 1;
                else if (x >= 1 && b[y + 1][x - 1] && !judge(x - 1, y + 1, 1)) a[y][x] = 1;
                else if (b[y + 1][x] && !judge(x, y + 1, 1)) a[y][x] = 1;
                else c[y][x]--;
            } else {
                b[y][x] = 0;
                if (a[y][x] && !judge(x, y, 0)) b[y][x] = 1;
                else if (a[y][x + 1] && !judge(x + 1, y, 0))b[y][x] = 1;
                else if (x >= 1 && b[y][x - 1] && !judge(x - 1, y, 1))b[y][x] = 1;
                else if (b[y][x + 1] && !judge(x + 1, y, 1))b[y][x] = 1;
                else c[y][x] -= 2;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (c[i][j] == 1)
                answer.push_back({j, i, 0});
            else if (c[i][j] == 2)
                answer.push_back({j, i, 1});
            else if (c[i][j] == 3)
                answer.push_back({j, i, 0}), answer.push_back({j, i, 1});
        }
    }
    sort(answer.begin(), answer.end(), comp);
    return answer;
}
