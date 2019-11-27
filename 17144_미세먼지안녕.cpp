/*
https://www.acmicpc.net/problem/17144
입력
첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.
둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다. 공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다.
-1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.
7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

7 8 2
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

7 8 50
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
출력
첫째 줄에 T초가 지난 후 구사과 방에 남아있는 미세먼지의 양을 출력한다.
188
188
46
*/
#include <bits/stdc++.h>
#define MAXI 50 + 1
using namespace std;
struct info { int y, x; };
struct cleaner { int x1, y1, x2, y2; };
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int cw[] = { 2,1,3,0 };
int acw[] = { 2,0,3,1 };
int MAP[MAXI][MAXI];
int tmp[MAXI][MAXI];
int R, C, T, res = 0;
cleaner air;
bool checkRange(int y, int x) { return (0 <= y && y < R && 0 <= x && x < C); }
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	air.y1 = -1, air.x1 = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1) {
				if (air.y1 == -1) air.y1 = i, air.x1 = j;
				else air.y2 = i, air.x2 = j;
			}
		}
	}
	while (T--) {
		queue<info> q;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (MAP[i][j] > 0)
					q.push({ i,j });

		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				tmp[i][j] = MAP[i][j];

		//미세먼지 확산
		while (!q.empty()) {
			info cur = q.front(); q.pop();

			int weight = tmp[cur.y][cur.x] / 5;
			for (int i = 0; i < 4; i++) {
				int nextY = cur.y + dy[i];
				int nextX = cur.x + dx[i];
				if (checkRange(nextY, nextX))
					if (tmp[nextY][nextX] > -1) {
						MAP[nextY][nextX] += weight;
						MAP[cur.y][cur.x] -= weight;
					}
			}
		}

		//공기청정기
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				tmp[i][j] = MAP[i][j];

		//시계방향
		MAP[air.y2][air.x2 + 1] = 0;
		int curY = air.y2; int curX = air.x2 + 1;
		for (int i = 0; i < 4; i++) {
			while (true) {
				int nextY = curY + dy[cw[i]];
				int nextX = curX + dx[cw[i]];
				if (nextY == air.y2 && nextX == air.x2) break;
				if (!(checkRange(nextY, nextX))) break;
				MAP[nextY][nextX] = tmp[curY][curX];
				curY = nextY, curX = nextX;
			}
		}
		//반시계방향
		MAP[air.y1][air.x1 + 1] = 0;
		curY = air.y1, curX = air.x1 + 1;
		for (int i = 0; i < 4; i++) {
			while (true) {
				int nextY = curY + dy[acw[i]];
				int nextX = curX + dx[acw[i]];
				if (nextY == air.y1 && nextX == air.x1) break;
				if (!(checkRange(nextY, nextX))) break;
				MAP[nextY][nextX] = tmp[curY][curX];
				curY = nextY, curX = nextX;
			}
		}
	}
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (MAP[i][j] > 0)
				res += MAP[i][j];
	cout << res << "\n";
}