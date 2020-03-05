/*
����
�����̴� ���̾�Ʈ�� ���� N��M ũ���� ü������ �޸����� �Ѵ�. ü������ 1��1 ũ���� ĭ���� �������� �ְ�, ĭ�� �� ĭ �Ǵ� ���̴�.
�� �ʸ��� �����̴� ��, �Ʒ�, ������, ���� �߿��� �̵��� ������ �ϳ� ����, �� �������� �ּ� 1��, �ִ� K���� �� ĭ�� �̵��Ѵ�.
������ (x1, y1)�� ������ (x2, y2)�� �־����� ��, ���������� ���������� �̵��ϴ� �ּ� �ð��� ���غ���.

�Է�
ù° �ٿ� ü������ ũ�� N�� M, 1�ʿ� �̵��� �� �ִ� ĭ�� �ִ� ���� K�� �־�����.
��° �ٺ��� N���� �ٿ��� ü������ ���°� �־�����. ü������ �� ĭ�� �� ĭ �Ǵ� ���̰�, �� ĭ�� '.', ���� '#'���� �־�����.
������ �ٿ��� �� ���� x1, y1, x2, y2�� �־�����. �� ĭ�� ���� �ٸ� ĭ�̰�, �׻� �� ĭ�̴�.
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
���
(x1, y1)���� (x2, y2)�� �̵��ϴ� �ּ� �ð��� ����Ѵ�. �̵��� �� ���� ��쿡�� -1�� ����Ѵ�.
3
8
-1

����
2 �� N, M, K �� 1,000
1 �� x1, x2 �� N
1 �� y1, y2 �� M
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