/*
����
���ϻ����� �������� �ʷϻ��� ���̸� ���� ������ ���Ѵ�.
����, ���ϻ����� ����� ���� �׸��� �ƴ� ����� ���� �׸����� �� �ٸ� �� �ִ�.

ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�. 
�׸��� �� ���� �������� �������� �ִµ�, ������ ���� ������ �̷���� �ִ�.
��, ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�. (������ ���̸� ���� ������ ���ϴ� ��쵵 ���� �����̶� �Ѵ�)

���� ���, �׸��� �Ʒ��� ���� ��쿡
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
���ϻ����� �ƴ� ����� ���� �� ������ ���� �� 4���̴�.
(���� 2, �Ķ� 1, �ʷ� 1) ������, ���ϻ����� ����� ������ 3�� �� �� �ִ�. (����-�ʷ� 2, �Ķ� 1)
�׸��� �Է����� �־����� ��, ���ϻ����� ����� ���� ���� �ƴ� ����� ���� �� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N �� 100)
��° �ٺ��� N�� �ٿ��� �׸��� �־�����.
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
���
���ϻ����� �ƴ� ����� ���� ���� ������ ������ ���ϻ����� ����� ���� ���� ������ ���� �������� ������ ����Ѵ�.
4 3
*/
#include <cstdio>
#include <string.h>
#include <queue>
#define MAX 101
using namespace std;
struct xy{
	int x;
	int y;
	char color;
};
int N;
char graph[MAX][MAX];
int check[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<xy> q;

void bfs(int x, int y, bool judge) {

	q.push({ x,y, graph[x][y] });
	check[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		char data = graph[curX][curY];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
				if (judge) {
					if (graph[nextX][nextY] == data && !check[nextX][nextY]) {
						check[nextX][nextY] = true;
						q.push({ nextX,nextY, graph[nextX][nextY] });
					}
				}
				else if (!judge) {
					if (data == 'R' || data == 'G') {
						if ((graph[nextX][nextY] == 'R' || graph[nextX][nextY] == 'G')
							&& !check[nextX][nextY]) {
							check[nextX][nextY] = true;
							q.push({ nextX, nextY, graph[nextX][nextY] });
						}
					}
					else if (data == 'B') {
						if (graph[nextX][nextY] == data && !check[nextX][nextY]) {
							check[nextX][nextY] = true;
							q.push({ nextX, nextY, graph[nextX][nextY] });
						}
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
			scanf("%s", &graph[i]);
	}
	
	int cnt = 0;
	memset(check, false, sizeof(check));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (!check[i][j]) {
				bfs(i, j, true);
				cnt++;
			}
	}
	printf("%d ", cnt);

	cnt = 0;
	memset(check, false, sizeof(check));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (!check[i][j]) {
				bfs(i, j, false);
				cnt++;
			}
	}
	printf("%d\n", cnt);

	return 0;
}