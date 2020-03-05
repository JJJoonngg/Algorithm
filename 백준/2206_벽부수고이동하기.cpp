/*
https://www.acmicpc.net/problem/2206
����
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. �ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����.
����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �̶� �ִ� ��η� �̵��Ϸ� �Ѵ�.
�ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �̶� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.

���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.

���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 1,000)�� �־�����. ���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.
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
���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.
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