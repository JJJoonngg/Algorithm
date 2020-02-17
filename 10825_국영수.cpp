//
// Created by 김종신 on 2020/02/17.
//
//단순정렬
#include <bits/stdc++.h>

#define MAXI 100001
using namespace std;
struct info {
    string name;
    int x, y, z;
};
int n, a, b, c;
string s;
info arr[MAXI];

bool comp(info a, info b) {
    if (a.x != b.x) return a.x > b.x;
    else if (a.x == b.x && a.y != b.y) return a.y < b.y;
    else if (a.x == b.x && a.y == b.y && a.z != b.z) return a.z > b.z;
    else return a.name < b.name;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].x >> arr[i].y >> arr[i].z;
    sort(arr, arr + n, comp);
    for (int i = 0; i < n; i++) cout << arr[i].name << "\n";

    return 0;
}