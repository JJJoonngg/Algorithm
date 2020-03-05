/*
�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�,
�� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
���
ù ��° �ٿ��� �� �������� ����Ͻÿ�.
�׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.
3
7
8
9
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 30
using namespace std;
int N, cnt = 0;
int map[MAX][MAX];
int siz[400];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y, int key) {
	map[x][y] = key;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N
			&& map[nextX][nextY] == 1)
			dfs(nextX, nextY, key);
	}
}
void solve(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 1)
				siz[map[i][j] - 2]++;
			printf("%d ", map[i][j]);
		}
		cout << endl;
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	solve(N);
	sort(siz, siz + cnt);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d\n", siz[i]);
	return 0;
}