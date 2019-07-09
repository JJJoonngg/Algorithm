/*
https://www.acmicpc.net/problem/11438
문제
N(2 ≤ N ≤ 100,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.

두 노드의 쌍 M(1 ≤ M ≤ 100,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.

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
#include <iostream>
#include <vector>
#define MAXI 100000+1
using namespace std;
int n, m;
vector<int> tree[MAXI];
int parent[MAXI][21], depth[MAXI];
void dfs(int cur, int d) {
	depth[cur] = d++;
	for (int i = 1; i <= 20; i++) parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
	for (auto next : tree[cur]) {
		if (!depth[next]) {
			parent[next][0] = cur;
			dfs(next, d);
		}
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) if (depth[b] <= depth[parent[a][i]]) a = parent[a][i];
	if (a == b) return a;
	for (int i = 20; i >= 0; i--) {
		if (parent[b][i] != parent[a][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (--n) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 1);
	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}