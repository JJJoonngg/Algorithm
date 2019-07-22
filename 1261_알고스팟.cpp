/*
https://www.acmicpc.net/problem/1261

����
�˰��� ����� ��� �̷ο� ������. �̷δ� N*M ũ���̸�, �� 1*1ũ���� ������ �̷���� �ִ�.
�̷δ� �� �� �Ǵ� ������ �̷���� �ְ�, �� ���� �����Ӱ� �ٴ� �� ������, ���� �μ��� ������ �̵��� �� ����.

�˰��� ����� ������������, �׻� ��� ���� �濡 �־�� �Ѵ�.
��, ���� ���� �ٸ� �濡 ���� ���� ����. � �濡�� �̵��� �� �ִ� ���� �����¿�� ������ �� ���̴�.
��, ���� ����� (x, y)�� ���� ��, �̵��� �� �ִ� ���� (x+1, y), (x, y+1), (x-1, y), (x, y-1) �̴�. ��, �̷��� ������ �̵� �� ���� ����.

���� ��ҿ��� �̵��� �� ������, �˰����� ���� AOJ�� �̿��� ���� �μ��� ���� �� �ִ�. ���� �μ���, �� ��� ������ ������ ���Ѵ�.

���� �� ������ �˰��̿� �ִٸ�, ������� �ñ��� ���� sudo�� �̿��� ���� �� ���� �� ���ֹ��� �� ������,
��Ÿ���Ե� �� ������ Baekjoon Online Judge�� ���ϵǾ� �ֱ� ������, sudo�� ����� �� ����.

���� (1, 1)�� �ִ� �˰��� ����� (N, M)���� �̵��Ϸ��� ���� �ּ� �� �� �μ���� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �̷��� ũ�⸦ ��Ÿ���� ���� ũ�� M, ���� ũ�� N (1 �� N, M �� 100)�� �־�����.
���� N���� �ٿ��� �̷��� ���¸� ��Ÿ���� ���� 0�� 1�� �־�����. 0�� �� ���� �ǹ��ϰ�, 1�� ���� �ǹ��Ѵ�.

(1, 1)�� (N, M)�� �׻� �շ��ִ�.
3 3
011
111
110

4 2
0001
1000

6 6
001111
010000
001111
110001
011010
100010
���
ù° �ٿ� �˰��� ����� (N, M)���� �̵��ϱ� ���� ���� �ּ� �� �� �μ���� �ϴ��� ����Ѵ�.
3
0
2

�˰��� �з�
���ͽ�Ʈ�� �˰���
*/
#include <iostream>
#include <queue>
#define MAXI 101
#define INF 1e9
using namespace std;
struct xy { int x, y; };
int map[MAXI][MAXI];
int dis[MAXI][MAXI];
int res = INF;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int M, N;
bool checkRange(int x, int y) { return 0 < x && x <= M && 0 < y && y <= N; }
void bfs() {
	queue<xy> q;
	q.push({ 1, 1 });
	dis[1][1] = 0;
	while (!q.empty()) {
		xy cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = cur.x + dx[i];
			int nextY = cur.y + dy[i];
			if (checkRange(nextX, nextY)) {
				if(map[nextX][nextY]) {
					if (dis[nextX][nextY] > dis[cur.x][cur.y] + 1) {
						dis[nextX][nextY] = dis[cur.x][cur.y] + 1;
						q.push({ nextX,nextY });
					}
				}
				else {
					if (dis[nextX][nextY] > dis[cur.x][cur.y]) {
						dis[nextX][nextY] = dis[cur.x][cur.y];
						q.push({ nextX,nextY });
					}
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d",&map[i][j]);
			dis[i][j] = INF;
		}
	}
	bfs();
	cout << dis[M][N] << "\n";
}