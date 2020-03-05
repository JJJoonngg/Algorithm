/*
Lowest Common Ancestor
����
N(2 �� N �� 50,000)���� �������� �̷���� Ʈ���� �־�����. 
Ʈ���� �� ������ 1������ N������ ��ȣ�� �Ű��� ������, ��Ʈ�� 1���̴�.

�� ����� �� M(1 �� M �� 10,000)���� �־����� ��, �� ����� ���� ����� ���� ������ �� ������ ����Ѵ�.

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
