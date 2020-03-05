/*
����
����̴� �� ������ ������ �̷���� �ǹ��� �����ִ�. �ǹ��� �Ϻο��� ���� ����, ����̴� �ⱸ�� ���� �ٰ� �ִ�.
�� �ʸ���, ���� �������� �������� ������ �� �������� ����������. ������ ���� ���� �ʴ´�. 
����̴� �������� ������ ĭ���� �̵��� �� ������, 1�ʰ� �ɸ���. ����̴� ���� ����� �� ����, 
���� �Ű��� ĭ �Ǵ� ���� ���� �������� ĭ���� �̵��� �� ����. ����̰� �ִ� ĭ�� ���� �ŰܿȰ� ���ÿ� �ٸ� ĭ���� �̵��� �� �ִ�.
������ ������ �־����� ��, �󸶳� ���� ������ Ż���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� �ִ� 100���̴�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ���� ������ �ʺ�� ���� w�� h�� �־�����. (1 �� w,h �� 1000)
���� h�� �ٿ��� w���� ����, ������ ������ �־�����.

'.': �� ����
'#': ��
'@': ������� ���� ��ġ
'*': ��
�� ������ @�� ������ �ϳ��̴�.
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###
���
�� �׽�Ʈ ���̽����� ������ Ż���ϴµ� ���� ���� �ð��� ����Ѵ�. ������ Ż���� �� ���� ��쿡�� "IMPOSSIBLE"�� ����Ѵ�.
2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct xy{
	int x;
	int y;
};
bool visit[MAX][MAX];
char map[MAX][MAX];
int w, h, t;
int startX, startY;
vector<xy> tmp;

int bfs() {
	queue<xy> fireQ;
	queue<xy> run;
	run.push({ startX,startY });
	visit[startX][startY] = true;

	for (int i = 0; i < tmp.size(); i++) {
		fireQ.push(tmp[i]);
	}

	int result = 0;

	while (!run.empty()) {
		int fireSize = fireQ.size();
		for (int k = 0; k < fireSize; k++) {
			int curX = fireQ.front().x;
			int curY = fireQ.front().y;
			fireQ.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {
					if (map[nextX][nextY] == '.') {
						map[nextX][nextY] = '*';
						fireQ.push({ nextX,nextY });
					}
				}
			}
		}
		int runSize = run.size();
		for (int k = 0; k < runSize; k++) {
			int curX = run.front().x;
			int curY = run.front().y;
			run.pop();

			if (curX == 0 || curX == h - 1 || curY == 0 || curY == w - 1) {
				return result + 1;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {
					if (map[nextX][nextY] != '#' && map[nextX][nextY] != '*' && !visit[nextX][nextY]) {
						visit[nextX][nextY] = true;
						run.push({ nextX,nextY });
					}
				}
			}
		}
		result++;
	}
	return -1;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		tmp.clear();
		memset(visit, false, sizeof(visit));
		memset(map, NULL, sizeof(map));

		scanf("%d %d", &w, &h);

		for (int i = 0; i < h; i++) {
			scanf("%s", &map[i]);
			for (int j = 0; j<w; j++) {
				if (map[i][j] == '@') {
					startX = i;
					startY = j;
				}
				else if (map[i][j] == '*') {
					tmp.push_back({ i,j });
				}
			}
		}
		int res = bfs();
		if (res >= 0) printf("%d\n", res);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}