/*
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 
입력으로 주어지는 간선은 양방향이다.
4 5 1
1 2
1 3
1 4
2 4
3 4

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
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