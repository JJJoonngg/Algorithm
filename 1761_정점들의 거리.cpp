/*
https://www.acmicpc.net/problem/1761
����
N(2��N��40,000)���� �������� �̷���� Ʈ���� �־�����
M(M��10,000)���� �� ��� ���� �Է¹��� �� �� ��� ������ �Ÿ��� ����϶�.

�Է�
ù° �ٿ� ����� ���� N�� �Էµǰ� ���� N-1���� �ٿ� Ʈ�� �� ����� �� ���� �Ÿ��� �Է¹޴´�.
�� ���� �ٿ� �Ÿ��� �˰� ���� M���� ��� ���� �� �ٿ� �� �־� �Էµȴ�.
�� �� ������ �Ÿ��� 10,000���� �۰ų� ���� �ڿ����̴�.

������ 1������ N������ ��ȣ�� �Ű��� �ִ�.
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
���
M���� �ٿ� ���ʴ�� �Է¹��� �� ��� ������ �Ÿ��� ����Ѵ�.
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