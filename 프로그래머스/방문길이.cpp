#include <string>

using namespace std;

int solution(string dirs) {
    int x = 5;
    int y = 5;
    int count = 0;
    int check[11][11][11][11];

    for (char cur : dirs) {
        if (cur == 'U') {
            if (y < 10) {
                if (check[x][y][x][y + 1] != 1) {
                    check[x][y][x][y + 1] = 1;
                    check[x][y + 1][x][y] = 1;
                    count++;
                }
                y++;
            }
        } else if (cur == 'D') {
            if (y > 0) {
                if (check[x][y][x][y - 1] != 1) {
                    check[x][y][x][y - 1] = 1;
                    check[x][y - 1][x][y] = 1;
                    count++;
                }
                y--;
            }
        } else if (cur == 'L') {
            if (x > 0) {
                if (check[x][y][x - 1][y] != 1) {
                    check[x][y][x - 1][y] = 1;
                    check[x - 1][y][x][y] = 1;
                    count++;
                }
                x--;
            }
        } else if (cur == 'R') {
            if (x < 10) {
                if (check[x][y][x + 1][y] != 1) {
                    check[x][y][x + 1][y] = 1;
                    check[x + 1][y][x][y] = 1;
                    count++;
                }
                x++;
            }
        }
    }
    return count;
}