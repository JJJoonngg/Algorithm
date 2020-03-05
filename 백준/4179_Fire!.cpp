/*
����
�����̴� �̷ο��� ���� �Ѵ�. �����̸� �̷ο��� Ż���ϵ��� ��������!
�̷ο����� �������� ��ġ�� ���� ���� ��ġ�� �����ؼ� �����̰� �ҿ� Ÿ������ Ż���� �� �ִ����� ����, 
�׸��� �󸶳� ���� Ż���� �� �ִ����� �����ؾ��Ѵ�.
�����̿� ���� �� �и��� ��ĭ�� ����Ǵ� ��������(�񽺵��ϰ� �̵����� �ʴ´�)  �̵��Ѵ�.
���� �� �������� �� �������� Ȯ��ȴ�.
�����̴� �̷��� �����ڸ��� ���� �������� Ż���� �� �ִ�.
�����̿� ���� ���� �ִ� ������ ������� ���Ѵ�.

�Է�
�Է��� ù° �ٿ��� �������� ���е� �� ���� R�� C�� �־�����. ��, 1 �� R, C �� 1000 �̴�.
R�� �̷� ���� ����, C�� ���� �����̴�.
���� �Է����� R�ٵ��� ������ �̷� ���� �־�����.
������ ���ڵ��� ������ ���Ѵ�.

#: ��
.: ������ �� �ִ� ����
J: �������� �̷ο����� �ʱ���ġ (������ �� �ִ� ����)
F: ���̳� ����
J�� �Է¿��� �ϳ��� �־�����.

4 4
####
#JF#
#..#
#..#

���
�����̰� ���� �����ϱ� ���� �̷θ� Ż�� �� �� ���°�� IMPOSSIBLE �� ����Ѵ�.
�����̰� �̷θ� Ż���� �� �ִ� ��쿡�� ���� ���� Ż��ð��� ����Ѵ�.
3
*/
#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 1001
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct xy {
	int x;
	int y;
};
char map[MAX][MAX];
bool visit[MAX][MAX];
int R, C;
int startX, startY;
queue<xy> fireQ;
queue<xy> Ji;

int bfs() {
	Ji.push({ startX,startY });
	visit[startX][startY] = true;
	int ans = 0;
	while (!Ji.empty()) {
		int fireSize = fireQ.size();
		for (int k = 0; k < fireSize; k++) {
			int curX = fireQ.front().x;
			int curY = fireQ.front().y;
			fireQ.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
					if (map[nextX][nextY] == '.' || map[nextX][nextY] == 'J') {
						map[nextX][nextY] = 'F';
						fireQ.push({ nextX,nextY });
					}
				}
			}
		}
		int curSize = Ji.size();
		for (int k = 0; k < curSize; k++) {
			int curX = Ji.front().x;
			int curY = Ji.front().y;
			Ji.pop();
			if (curX == 0 || curX == R - 1 || curY == 0 || curY == C - 1) 
				return ans + 1;
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C) {
					if (map[nextX][nextY] == '.' && !visit[nextX][nextY]) {
						visit[nextX][nextY] = true;
						Ji.push({ nextX,nextY });
					}
				}
			}
		}
		ans++;
	}
	return -1;
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; map[i][j] != '\0'; j++) {
			if (map[i][j] == 'J') {
				startX = i;
				startY = j;
			}
			else if (map[i][j] == 'F') {
				fireQ.push({ i,j });
			}
		}
	}
	int result = bfs();
	if (result>=0) printf("%d\n", result);
	else printf("IMPOSSIBLE\n");
	return 0;
}