//
// Created by 김종신 on 2020/05/07.
//
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key) {
    int keySiz = key.size();
    vector<vector<int>> tmp(keySiz, (vector<int>(keySiz, 0)));
    for (int i = keySiz - 1; i >= 0; i--)
        for (int j = 0; j < keySiz; j++)
            tmp[j][i] = key[keySiz - i - 1][j];
    return tmp;
}

bool checkRes(int x, int y, vector<vector<int>> key, vector<vector<int>> board, int lockSiz) {
    int keySiz = key.size();

    for (int i = x; i < x + keySiz; i++)
        for (int j = y; j < y + keySiz; j++)
            board[i][j] += key[i - x][j - y];

    for (int i = 0; i < lockSiz; i++)
        for (int j = 0; j < lockSiz; j++)
            if (board[lockSiz + i][lockSiz + j] != 1)
                return false;

    return true;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    int keySiz = key.size(), lockSiz = lock.size();
    vector<vector<int>> board(lockSiz * 3, (vector<int>(lockSiz * 3, 0)));
    for (int i = 0; i < lockSiz; i++)
        for (int j = 0; j < lockSiz; j++)
            board[lockSiz + i][lockSiz + j] = lock[i][j];

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < board.size() - keySiz + 1; i++) {
            for (int j = 0; j < board.size() - keySiz + 1; j++) {
                if (checkRes(i, j, key, board, lockSiz))
                    return true;
            }
        }
        key = rotate(key);
    }
    return false;
}