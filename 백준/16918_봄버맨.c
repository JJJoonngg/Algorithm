/*
https://www.acmicpc.net/problem/16918
�Է�
ù° �ٿ� R, C, N (1 �� R, C, N �� 200)�� �־�����. ��° �ٺ��� R���� �ٿ� �������� �ʱ� ���°� �־�����. �� ĭ�� '.'��, ��ź�� 'O'�� �־�����.
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
���
�� R���� �ٿ� N�ʰ� ���� ���� ������ ���¸� ����Ѵ�.
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