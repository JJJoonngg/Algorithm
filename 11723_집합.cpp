//
// Created by 김종신 on 2020/02/29.
//
#include <bits/stdc++.h>

using namespace std;
int M, tmp;
bool arr[30] = {false,};
string input;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> M;
    while (M--) {
        cin >> input;
        if (input == "add") {
            cin >> tmp;
            arr[tmp] = true;
        } else if (input == "remove") {
            cin >> tmp;
            arr[tmp] = false;
        } else if (input == "check") {
            cin >> tmp;
            cout << arr[tmp] << "\n";
        } else if (input == "toggle") {
            cin >> tmp;
            arr[tmp] = !arr[tmp];
        } else if (input == "all") {
            //fill(arr, arr + 21, 1);
            memset(arr, true, sizeof(arr));
        } else if (input == "empty") {
            //fill(arr, arr + 21, 0);
            memset(arr, false, sizeof(arr));
        }
    }
    return 0;
}