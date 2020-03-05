/*
����
���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. 
(1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) ��° �ٺ��� M���� �ٿ� ������ �� ���� u�� v�� �־�����. (1 �� u, v �� N, u �� v) ���� ������ �� ���� �־�����.
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
���
ù° �ٿ� ���� ����� ������ ����Ѵ�.
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