/*
https://www.acmicpc.net/problem/16918
입력
첫째 줄에 R, C, N (1 ≤ R, C, N ≤ 200)이 주어진다. 둘째 줄부터 R개의 줄에 격자판의 초기 상태가 주어진다. 빈 칸은 '.'로, 폭탄은 'O'로 주어진다.
6 7 3
.......
...O...
....O..
.......
OO.....
OO.....

6 7 4
.......
...O...
....O..
.......
OO.....
OO.....

6 7 5
.......
...O...
....O..
.......
OO.....
OO.....
출력
총 R개의 줄에 N초가 지난 후의 격자판 상태를 출력한다.
OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO

OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO

.......
...O...
....O..
.......
OO.....
OO.....
*/
#include <stdio.h>
#define MAXI 222
int R, C, N;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int boom[MAXI][MAXI];
char map[MAXI][MAXI];
int main() {
	scanf("%d %d %d", &R, &C, &N);
	for (int i = 0; i < R; i++)
		scanf("%s", map[i]);		

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] == 'O')
				boom[i][j] = 3;

	for (int time = 1; time <= N; time++) {

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (boom[i][j] == time) {
					map[i][j] = '.';
					for (int k = 0; k < 4; k++) {
						int nextX = i + dx[k];	int nextY = j + dy[k];
						if (0 <= nextX && nextX < R && 0 <= nextY && nextY < C)		
							map[nextX][nextY] = '.';
					}
				}
			}
		}

		if (time % 2 == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (map[i][j] == '.') {
						map[i][j] = 'O';
						boom[i][j] = time + 3;
					}
				}
			}
		}

	}

	for (int i = 0; i < R; i++) 
			printf("%s\n", map[i]);
	return 0;
}