/*
https://www.acmicpc.net/problem/11438
����
N(2 �� N �� 100,000)���� �������� �̷���� Ʈ���� �־�����. Ʈ���� �� ������ 1������ N������ ��ȣ�� �Ű��� ������, ��Ʈ�� 1���̴�.

�� ����� �� M(1 �� M �� 100,000)���� �־����� ��, �� ����� ���� ����� ���� ������ �� ������ ����Ѵ�.

�Է�
ù° �ٿ� ����� ���� N�� �־�����, ���� N-1�� �ٿ��� Ʈ�� �󿡼� ����� �� ������ �־�����. 
�� ���� �ٿ��� ���� ����� ���� ������ �˰���� ���� ���� M�� �־�����, ���� M�� �ٿ��� ���� ���� �־�����.
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
���
M���� �ٿ� ���ʴ�� �Է¹��� �� ������ ���� ����� ���� ������ ����Ѵ�.
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