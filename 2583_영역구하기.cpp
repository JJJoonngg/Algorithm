/*
����
������ ������ 1�� M��N(M,N��100)ũ���� �����̰� �ִ�. �� ������ ���� ���ݿ� ���߾� K���� ���簢���� �׸� ��, 
�̵� K���� ���簢���� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ����������.
���� ��� M=5, N=7 �� ������ ���� <�׸� 1>�� ���� ���簢�� 3���� �׷ȴٸ�, �� ������ ������ <�׸� 2>�� ���� 3���� �и��� �������� ���������� �ȴ�.
<�׸� 2>�� ���� �и��� �� ������ ���̴� ���� 1, 7, 13�� �ȴ�.
M, N�� K �׸��� K���� ���簢���� ��ǥ�� �־��� ��, K���� ���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������, 
�׸��� �и��� �� ������ ���̰� �������� ���Ͽ� �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� M�� N, �׸��� K�� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. M, N, K�� ��� 100 ������ �ڿ����̴�. 
��° �ٺ��� K���� �ٿ��� �� �ٿ� �ϳ��� ���簢���� ���� �Ʒ� �������� x, y��ǥ���� ������ �� �������� x, y��ǥ���� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����.
�������� ���� �Ʒ� �������� ��ǥ�� (0,0)�̰�, ������ �� �������� ��ǥ��(N,M)�̴�. �ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����.
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
���
ù° �ٿ� �и��Ǿ� ���������� ������ ������ ����Ѵ�. ��° �ٿ��� �� ������ ���̸� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ����Ѵ�.
3
1 7 13
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
int M, N, K, visit[MAX][MAX] = { 0, }, arr[MAX][MAX] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct compare { bool operator()(int& l, int &r) { return l > r; } };
priority_queue<int, vector<int>, compare> res;

int checkRange(int x, int y) { return (0 <= x && x < N && 0 <= y && y < M); }
int dfs(int x, int y) {
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (checkRange(nextX, nextY) && !arr[nextY][nextX] && !visit[nextY][nextX]) {
			visit[nextY][nextX]++;
			cnt += dfs(nextX, nextY);
		}
	}
	return cnt;
}
int main() {
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				arr[y][x]++;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!arr[i][j] && !visit[i][j]) {
				visit[i][j]++;
				res.push(dfs(j, i));
			}
		}
	}

	printf("%d\n", res.size());

	while (!res.empty()) {
		printf("%d ", res.top());
		res.pop();
	}
	printf("\n");
	return 0;
}