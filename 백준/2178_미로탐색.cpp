/*
����
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.
1 0 1 1 1 1
1 0 1 0 1 0
1 0 1 0 1 1
1 1 1 0 1 1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.
�̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2��N, M��100)�� �־�����.
���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.
4 6
101111
101010
101011
111011

4 6
110110
110110
111111
111101

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�.
�׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.
15
9
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX 101
char graph[MAX][MAX];
int check[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct xy
{
	int x;
	int y;
};
queue<xy> q;
void bfs() {
	q.push({ 1,1 });
	check[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (graph[x + dx[i]][y + dy[i]] == '1' && check[x + dx[i]][y + dy[i]] == 1) {
				q.push({ x + dx[i],y + dy[i] });
				check[x + dx[i]][y + dy[i]] = check[x][y] + 1;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check[i][j] = -1;
			cin >> graph[i][j];
			if (graph[i][j] == '1') check[i][j] = 1;
		}
	}
	bfs();
	cout << check[N][M] << endl;
	return 0;
}