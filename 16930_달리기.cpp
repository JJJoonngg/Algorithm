/*
문제
진영이는 다이어트를 위해 N×M 크기의 체육관을 달리려고 한다. 체육관은 1×1 크기의 칸으로 나누어져 있고, 칸은 빈 칸 또는 벽이다.
매 초마다 진영이는 위, 아래, 오른쪽, 왼쪽 중에서 이동할 방향을 하나 고르고, 그 방향으로 최소 1개, 최대 K개의 빈 칸을 이동한다.
시작점 (x1, y1)과 도착점 (x2, y2)가 주어졌을 때, 시작점에서 도착점으로 이동하는 최소 시간을 구해보자.

입력
첫째 줄에 체육관의 크기 N과 M, 1초에 이동할 수 있는 칸의 최대 개수 K가 주어진다.
둘째 줄부터 N개의 줄에는 체육관의 상태가 주어진다. 체육관의 각 칸은 빈 칸 또는 벽이고, 빈 칸은 '.', 벽은 '#'으로 주어진다.
마지막 줄에는 네 정수 x1, y1, x2, y2가 주어진다. 두 칸은 서로 다른 칸이고, 항상 빈 칸이다.
3 4 4
....
###.
....
1 1 3 1

3 4 1
....
###.
....
1 1 3 1

2 2 1
.#
#.
1 1 2 2
출력
(x1, y1)에서 (x2, y2)로 이동하는 최소 시간을 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.
3
8
-1

제한
2 ≤ N, M, K ≤ 1,000
1 ≤ x1, x2 ≤ N
1 ≤ y1, y2 ≤ M
*/
#include <iostream>
#include <queue>
#define MAX 1002
using namespace std;
struct xyc { int x;	int y; int cnt; };
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char map[MAX][MAX];
bool visit[MAX][MAX];
int n, m, k;
int startX, startY, defX, defY;
int checkRange(int x, int y) { return (1 <= x && x <= n && 1 <= y && y <= m); }
void bfs() {
	queue<xyc> Jin;
	Jin.push({ startX ,startY ,0 });
	visit[startX][startY] = true;
	while (!Jin.empty()) {
		xyc cur = Jin.front();
		Jin.pop();
		if (cur.x == (defX) && cur.y == (defY )) {
			cout << cur.cnt << "\n";
			return;
		}
		for (int j = 0; j < 4; j++) {
			xyc tmp = cur;
			for (int l = 0; l < k; l++) {
				int nextX = tmp.x + dx[j];
				int nextY = tmp.y + dy[j];
				if (checkRange(nextX, nextY) && map[nextX][nextY] == '.') {
					if (!visit[nextX][nextY]) {
						visit[nextX][nextY] = true;
						Jin.push({ nextX,nextY,cur.cnt + 1 });
					}
					tmp.x = nextX;	tmp.y = nextY;
				}
				else break;
			}
		}
	}
	cout << -1 << "\n";
	return;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)	for (int j = 1; j <= m; j++) cin >> map[i][j];
	cin >> startX >> startY >> defX >> defY;
	bfs();
	return 0;
}