/*
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. 
(1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
6 5
1 2
2 5
5 1
3 4
4 6

6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
출력
첫째 줄에 연결 요소의 개수를 출력한다.
2
1
*/
#include <cstdio>
#include <vector>
#define MAX 1001
using namespace std;
vector<int> graph[MAX];
bool visit[MAX];
int N, M;
void dfs(int node) {
	visit[node] = true;
	for (auto next : graph[node]) {
		if (!visit[next]) dfs(next);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			res += 1;
		}
	}

	printf("%d\n", res);

	return 0;
}