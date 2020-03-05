//
// Created by 김종신 on 2020/02/29.
//
#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> input;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }
    int cnt = 0;
    do {
        if (cnt == 1) {
            for (int i = 0; i < input.size(); i++)
                cout << input[i] << " ";
            cout << "\n";
            return 0;
        }
        cnt++;
    } while (prev_permutation(input.begin(), input.end()));
    cout << "-1\n";
    return 0;
}