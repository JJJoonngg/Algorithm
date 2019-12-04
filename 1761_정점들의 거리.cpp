/*
https://www.acmicpc.net/problem/1761
문제
N(2≤N≤40,000)개의 정점으로 이루어진 트리가 주어지고
M(M≤10,000)개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.

입력
첫째 줄에 노드의 개수 N이 입력되고 다음 N-1개의 줄에 트리 상에 연결된 두 점과 거리를 입력받는다.
그 다음 줄에 거리를 알고 싶은 M개의 노드 쌍이 한 줄에 한 쌍씩 입력된다.
두 점 사이의 거리는 10,000보다 작거나 같은 자연수이다.

정점은 1번부터 N번까지 번호가 매겨져 있다.
7
1 6 13
6 3 9
3 5 7
4 1 3
2 4 20
4 7 2
3
1 6
1 4
2 6
출력
M개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 출력한다.
13
3
36
*/
#include <bits/stdc++.h>
#define MAXI 40000 + 1
using namespace std;
struct info { int node, cost; };
vector<info> graph[MAXI];
int parent[MAXI][21], depth[MAXI], dist[MAXI];
int n, m;
void dfs(int cur, int d, int cost) {
	depth[cur] = d++;
	dist[cur] = cost;
	for (int i = 1; i <= 20; i++)
		parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
	for (auto a : graph[cur]) {
		if (!depth[a.node]) {
			parent[a.node][0] = cur;
			dfs(a.node, d, cost + a.cost);
		}
	}
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (depth[y] <= depth[parent[x][i]])
			x = parent[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (parent[y][i] != parent[x][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while(--n){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	dfs(1, 1, 0);
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		int tmp = lca(x, y);
		cout << dist[x] + dist[y] - 2 * dist[tmp] << "\n";
	}
}