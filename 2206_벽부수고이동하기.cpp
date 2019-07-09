/*
https://www.acmicpc.net/problem/2206
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다.
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.
6 4
0100
1110
1000
0000
0111
0000

4 4
0111
1111
1111
1110
출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
15
-1
*/
#include <iostream>
#include <queue>
#define MAXI 1000 + 1
using namespace std;
int arr[MAXI][MAXI] = { 0, }, n, m;
bool checkRange(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
struct info { int x; int y; int penetration; };
int visit[MAXI][MAXI][2] = { 0, };
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
queue<info> q;
int bfs() {
	q.push({ 0,0,true });
	visit[0][0][1] = true;
	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int check = q.front().penetration;
		q.pop();
		if (curX == n - 1 && curY == m - 1)
			return visit[curX][curY][check];
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (checkRange(nextX, nextY)) {
				if (arr[nextX][nextY] && check) {
					visit[nextX][nextY][check - 1] = visit[curX][curY][check] + 1;
					q.push({ nextX,nextY,check - 1 });
				}
				else if (!arr[nextX][nextY] && !visit[nextX][nextY][check]) {
					visit[nextX][nextY][check] = visit[curX][curY][check] + 1;
					q.push({ nextX,nextY,check });
				}
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	printf("%d\n", bfs());
}