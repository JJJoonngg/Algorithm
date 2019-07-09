/*
����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�.
1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. 
ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�,
������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. 
�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.
������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, 
�� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
���
ù ��° �ٿ��� �� �������� ����Ͻÿ�.
�׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.
3
7
8
9
*/
#include <cstdio>
#include <queue>
#include <functional>
#define MAX 26
using namespace std;
struct xy {
	int x;
	int y;
	int group;
};
int cnt = 0;
int N;
int house[MAX][MAX];
int check[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<xy> q;
priority_queue<int, vector<int>, greater<int>> num;

void bfs(int x, int y) {
	int count = 1;
	q.push({ x,y, house[x][y] });
	check[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
				if (!check[nextX][nextY] && house[nextX][nextY]) {
					check[nextX][nextY] = true;
					q.push({ nextX,nextY,house[nextX][nextY] });
					count++;
				}
			}
		}
	}
	num.push(count);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			scanf("%1d", &house[i][j]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (!check[i][j] && house[i][j]) {
				bfs(i, j);
				cnt++;
			}
	}
	printf("%d\n", cnt);
	while (cnt--) {
		printf("%d\n", num.top());
		num.pop();
	}
	return 0;
}