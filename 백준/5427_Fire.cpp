/*
문제
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.
매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 
상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 
불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.
빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.
각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)
다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.
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
출력
각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.
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