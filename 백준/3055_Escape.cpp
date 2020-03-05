/*
����
����� ������ ���� �̹����� ���� ���� ������ �տ� �־���, �� �ɷ��� �����غ��� ���� ��ó�� Ƽ������ ȫ���� ����Ű���� �Ѵ�. 
�� ������ ����ġ�� �� ���� ��� �ִ�. ����ġ�� ���� ģ�� ģ���� ����� ���� ������ ���� ������ ȫ���� ���Ϸ��� �Ѵ�.
Ƽ������ ������ R�� C���� �̷���� �ִ�. ����ִ� ���� '.'�� ǥ�õǾ� �ְ�, ���� ���ִ� ������ '*', ���� 'X'�� ǥ�õǾ� �ִ�. 
����� ���� 'D'��, ����ġ�� ��ġ�� 'S'�� ��Ÿ������ �ִ�.
�� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ �� �ϳ��� �̵��� �� �ִ�. 
(��, �Ʒ�, ������, ����) ���� �� �и��� ����ִ� ĭ���� Ȯ���Ѵ�. 
���� �ִ� ĭ�� �������ִ� ����ִ� ĭ(��� �� ���� ����)�� ���� ���� �ȴ�. 
���� ����ġ�� ���� ����� �� ����. ��, ����ġ�� ���� ���ִ� �������� �̵��� �� ����, ���� ����� �ұ��� �̵��� �� ����.
Ƽ������ ������ �־����� ��, ����ġ�� �����ϰ� ����� ���� �̵��ϱ� ���� �ʿ��� �ּ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����ġ�� ���� �� ������ ĭ���� �̵��� �� ����. ��, ���� �ð��� ���� �� ������ ĭ���� ����ġ�� �̵��� �� ����.
�̵��� �� ������ ����ġ�� ���� ������ �����̴�.

�Է�
ù° �ٿ� 50���� �۰ų� ���� �ڿ��� R�� C�� �־�����.
���� R�� �ٿ��� Ƽ������ ������ �־�����, �������� ������ ���ڸ� �־�����. 'D'�� 'S'�� �ϳ����� �־�����.
3 3
D.*
...
.S.

3 3
D.*
...
..S

3 6
D...*.
.X.X..
....S.

5 4
.D.*
....
..X.
S.*.
....
���
ù° �ٿ� ����ġ�� ����� ���� �̵��� �� �ִ� ���� ���� �ð��� ����Ѵ�. 
����, �����ϰ� ����� ���� �̵��� �� ���ٸ�, "KAKTUS"�� ����Ѵ�.
3
KAKTUS
6
4
*/
#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 51
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct xy
{
	int x;
	int y;
};
int R, C;
char map[MAX][MAX];
int water[MAX][MAX];
bool visit[MAX][MAX];
int startX, startY;
int desX, desY;
queue<xy> water_queue;
queue<xy> mole;

void bfs() {
	mole.push({ startX,startY });
	visit[startX][startY] = true;
	while (!mole.empty()) {
		int waterSize = water_queue.size();
		for (int k = 0; k < waterSize; k++) {
			int curX = water_queue.front().x;
			int curY = water_queue.front().y;
			water_queue.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < R &&nextY >= 0 && nextY < C) {
					if (map[nextX][nextY] == '.') {
						map[nextX][nextY] = '*';
						water_queue.push({ nextX,nextY });
					}
				}
			}
		}
		int moleSize = mole.size();
		for (int k = 0; k < moleSize; k++) {
			int curX = mole.front().x;
			int curY = mole.front().y;
			mole.pop();
			if (map[curX][curY] == 'D') {
				visit[desX][desY] = true;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < R &&nextY >= 0 && nextY < C) {
					if (map[nextX][nextY] == 'D') {
						visit[nextX][nextY] = true;
						water[nextX][nextY] = water[curX][curY] + 1;
						return;
					}
					else if (map[nextX][nextY] != 'X'&&map[nextX][nextY] != '*' && !visit[nextX][nextY]) {
						mole.push({ nextX,nextY });
						water[nextX][nextY] = water[curX][curY] + 1;
						visit[nextX][nextY] = true;
					}
				}
			}
		}
	}

}
int main() {

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; map[i][j] !='\0'; j++) {
			if (map[i][j] == 'S') {
				startX = i;
				startY = j;
			}
			else if (map[i][j] == 'D') {
				desX = i;
				desY = j;
			}
			else if (map[i][j] == '*') {
				water_queue.push({ i,j });
			}
		}
	}
	bfs();
	if (visit[desX][desY]) printf("%d\n", water[desX][desY]);
	else printf("KAKTUS\n");
	return 0;
}