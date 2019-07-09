/*
문제
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다.
따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다.
(빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
둘째 줄부터 N개 줄에는 그림이 주어진다.
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
출력
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
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