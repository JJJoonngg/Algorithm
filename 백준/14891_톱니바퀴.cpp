//
// Created by 김종신 on 2020/02/28.
//
#include <bits/stdc++.h>

using namespace std;
deque<int> gear[5];
char input;
int K, a, b, res = 0;

void rotation(int num, int dir) {
    int tmp;
    if (dir == -1) {
        tmp = gear[num].front();
        gear[num].pop_front();
        gear[num].push_back(tmp);
        return;
    } else if (dir == 1) {
        tmp = gear[num].back();
        gear[num].pop_back();
        gear[num].push_front(tmp);
        return;
    }
}

void left(int num, int dir) {
    if (num == 0 || num == 5) return;
    if (gear[num][2] != gear[num + 1][6]) {
        left(num - 1, -dir);
        rotation(num, dir);
    }
}

void right(int num, int dir) {
    if (num == 0 || num == 5) return;
    if (gear[num - 1][2] != gear[num][6]) {
        right(num + 1, -dir);
        rotation(num, dir);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> input;
            gear[i].push_back(input - '0');
        }
    }
    cin >> K;
    while (K--) {
        cin >> a >> b;
        left(a - 1, -b);
        right(a + 1, -b);
        rotation(a, b);
    }

    res += gear[1][0] == 0 ? 0 : 1;
    res += gear[2][0] == 0 ? 0 : 2;
    res += gear[3][0] == 0 ? 0 : 4;
    res += gear[4][0] == 0 ? 0 : 8;

    cout << res << "\n";

    return 0;
}