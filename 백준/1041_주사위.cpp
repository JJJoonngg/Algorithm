#include <bits/stdc++.h>

constexpr auto INF = 1e9;
constexpr auto siz = 6;
using namespace std;
long long res = 0, n, dice[siz], one = INF, two = INF, three = INF;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1) {
        res = 0;
        long long tmp = 0;
        for (int i = 0; i < siz; i++) {
            cin >> dice[i];
            tmp = max(dice[i], tmp);
            res += dice[i];
        }
        cout << res - tmp << "\n";
        return 0;
    }

    for (int i = 0; i < siz; i++) {
        cin >> dice[i];
        one = min(one, dice[i]);
    }

    res += ((n - 2) * (n - 1) * 4 + (n - 2) * (n - 2)) * one;

    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            if (i == j || i + j == 5) continue;
            two = min(two, dice[i] + dice[j]);
        }
    }
    res += ((n - 1) * 4 + (n - 2) * 4) * two;


    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            for (int k = 0; k < siz; k++) {
                if (i == j || i == k || j == k)continue;
                if (i + j == 5 || i + k == 5 || j + k == 5) continue;
                three = min(three, dice[i] + dice[j] + dice[k]);
            }
        }
    }
    res += three * 4;
    cout << res << "\n";
    return 0;
}