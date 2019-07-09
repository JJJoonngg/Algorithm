/*
����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����.
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. �� ������ ���� �� �־��� ���� �ִµ�, ������ �ϳ��� �ִ� ������ �����ϸ� �ȴ�. 
�Է����� �־����� ������ ������̴�.
4 5 1
1 2
1 3
1 4
2 4
3 4

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.
1 2 4 3
1 2 3 4
*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 1001
int graph[MAX][MAX];
bool visit[MAX] = { 0, };
void DFS(int V, int N) {
	visit[V] = 1;
	cout << V << ' ';
	for (int i = 1; i <= N; i++) {
		if (graph[V][i] == 0 || visit[i] == 1) continue;
		DFS(i, N);
	}
}
void BFS(int V, int N) {
	queue<int> Q;
	Q.push(V);
	visit[V] = 1;
	while (!Q.empty()){
		V = Q.front();
		cout << Q.front() << ' ';
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[V][i] == 1 && visit[i] == 0) {
				Q.push(i);
				visit[i] = 1;
			}
		}

	}
}
int main() {
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	DFS(V, N);
	memset(visit,0,sizeof(visit));
	cout << endl;
	BFS(V, N);
	return 0;
}