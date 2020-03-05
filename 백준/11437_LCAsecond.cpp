/*
Lowest Common Ancestor
문제
N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 주어진다. 
트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.

두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.

입력
첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 줄에는 트리 상에서 연결된 두 정점이 주어진다.
그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 다음 M개 줄에는 정점 쌍이 주어진다.
15
1 2
1 3
2 4
3 7
6 2
3 8
4 9
2 5
5 11
7 13
10 4
11 15
12 5
14 7
6
6 11
10 9
2 6
7 6
8 13
8 15

출력
M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.
2
4
2
1
3
1
*/
#include <cstdio>
#include <vector>
#define	MAX 50001
using namespace std;
vector<int> graph[MAX];
int parent[MAX], depth[MAX];
void dfs(int now, int cnt) {
	depth[now] = cnt++;
	for (auto i : graph[now]) {
		if (!depth[i]) {
			dfs(i, cnt);
			parent[i] = now;
		}
	}
}

int main() {
	int N, M;
	scanf("%d", &N);
	while (--N) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (depth[a] < depth[b]) swap(a, b);
		while (depth[a] != depth[b]) a = parent[a];
		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
		printf("%d\n", a);
	}

	return 0;
}
