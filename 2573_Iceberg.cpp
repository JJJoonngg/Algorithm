/*
�Է�
ù �ٿ��� ������ �迭�� ���� ������ ���� ������ ��Ÿ���� �� ���� N�� M�� �� ���� ��ĭ�� ���̿� �ΰ� �־�����.
N�� M�� 3 �̻� 300 �����̴�. 
�� ���� N���� �ٿ��� �� �ٸ��� �迭�� �� ���� ��Ÿ���� M���� ������ �� ���� �� ĭ�� ���̿� �ΰ� �־�����.
�� ĭ�� ���� ���� 0 �̻� 10 �����̴�. 
�迭���� ������ �����ϴ� ĭ�� ����, ��, 1 �̻��� ������ ���� ĭ�� ������ 10,000 �� �����̴�.
�迭�� ù ��° ��� ��, ������ ��� ������ �׻� 0���� ä������.
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
���
ù �ٿ� ������ �и��Ǵ� ������ �ð�(��)�� ����Ѵ�. ���� ������ �� ���� ������ �и����� ������ 0�� ����Ѵ�.
2
*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define MAX 301
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[MAX][MAX];
int melt[MAX][MAX];
int visit[MAX][MAX];
int N, M, res;
int checkRange(int x, int y) {return (0 <= x && x < M && 0 <= y && y < N);}
void dfs(int x, int y) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		if (!visit[nextY][nextX] && map[nextY][nextX] > 0 && checkRange(nextX, nextY)) {
			dfs(nextX, nextY);
		}
	}
}

int cntIceberg() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && map[i][j] > 0) {
				cnt++;
				dfs(j, i);
			}
		}
	}
	return cnt;
}
int nextYear(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		if (map[nextY][nextX] <= 0 && map[y][x] > 0 && checkRange(nextX, nextY))
			cnt++;
	}
	return cnt++;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	int tmp = 0;
	while ((tmp = cntIceberg()) < 2) {
		memset(visit, 0, sizeof(visit));
		if (tmp == 0) {
			res = 0;
			break;
		}	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0) melt[i][j] = nextYear(j, i);
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] -= melt[i][j];
		res++;
	}
	printf("%d\n", res);

	return 0;
}