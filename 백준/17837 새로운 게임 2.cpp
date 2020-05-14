//
// Created by 김종신 on 2020/05/14.
//
//메모리 참조 문제가 발생하여 https://11001.tistory.com/28 코드 참조
//
#include <bits/stdc++.h>

using namespace std;
struct xyd {
    int x, y, d;
};
int n, k, x, y, d;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int changeDir[] = {0, 2, 1, 4, 3};
xyd pawn[11];
int boardColor[13][13];
vector<int> board[13][13];

bool checkRange(int a, int b) { return 0 < a && a <= n && 0 < b && b <= n; }

int movePawn(int num) {
    int nx = pawn[num].x + dx[pawn[num].d];
    int ny = pawn[num].y + dy[pawn[num].d];
    if (!checkRange(nx, ny) || boardColor[nx][ny] == 2) {
        pawn[num].d = changeDir[pawn[num].d];
        nx = pawn[num].x + dx[pawn[num].d];
        ny = pawn[num].y + dy[pawn[num].d];
        if (!checkRange(nx, ny) || boardColor[nx][ny] == 2)
            return 0;
    }
    vector<int> &cur = board[pawn[num].x][pawn[num].y];
    vector<int> &next = board[nx][ny];

    auto tmp = find(cur.begin(), cur.end(), num);

    if (boardColor[nx][ny] == 1)
        reverse(tmp, cur.end());

    for (auto it = tmp; it != cur.end(); it++) {
        pawn[*it].x = nx, pawn[*it].y = ny;
        next.push_back(*it);
    }
    cur.erase(tmp, cur.end());
    return next.size();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> boardColor[i][j];

    for (int i = 0; i < k; i++) {
        cin >> x >> y >> d;
        pawn[i] = {x, y, d};
        board[x][y].push_back(i);
    }
    int cnt;
    bool flag = false;
    for (cnt = 1; cnt <= 1000; cnt++) {
        for (int i = 0; i < k; i++) {
            if (movePawn(i) >= 4) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) cout << "-1\n";
    else cout << cnt << "\n";

    return 0;
}