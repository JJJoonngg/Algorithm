/*
문제
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 
그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다.
불은 각 지점에서 네 방향으로 확산된다.
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다.
R은 미로 행의 개수, C는 열의 개수이다.
다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이난 공간
J는 입력에서 하나만 주어진다.

4 4
####
#JF#
#..#
#..#

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는경우 IMPOSSIBLE 을 출력한다.
지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.
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