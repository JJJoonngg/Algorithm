/*
����
�׷����� ������ ������ �ѷ� �����Ͽ�, �� ���տ� ���� ���������� ���� �������� �ʵ��� ������ �� ���� ��, 
�׷��� �׷����� Ư���� �̺� �׷��� (Bipartite Graph) �� �θ���.

�׷����� �Է����� �־����� ��, �� �׷����� �̺� �׷������� �ƴ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �����Ǿ� �ִµ�, ù° �ٿ� �׽�Ʈ ���̽��� ���� K(2��K��5)�� �־�����.
�� �׽�Ʈ ���̽��� ù° �ٿ��� �׷����� ������ ���� V(1��V��20,000)�� ������ ���� E(1��E��200,000)�� �� ĭ�� ���̿� �ΰ� ������� �־�����. 
�� �������� 1���� V���� ���ʷ� ��ȣ�� �پ� �ִ�. �̾ ��° �ٺ��� E���� �ٿ� ���� ������ ���� ������ �־����µ�, 
�� �ٿ� ������ �� ������ ��ȣ�� �� ĭ�� ���̿� �ΰ� �־�����.
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
���
K���� �ٿ� ���� �Է����� �־��� �׷����� �̺� �׷����̸� YES, �ƴϸ� NO�� ������� ����Ѵ�.
YES
NO
*/
#include <iostream>
#include <string.h>
#include <vector>
#define MAX 20001
using namespace std;
int k, v, e;
vector<int> graph[MAX];
int check[MAX];

void dfs(int num, int color) {
	check[num] = color;
	for (int i = 0; i < graph[num].size(); i++) {
		if (!check[graph[num][i]]) dfs(graph[num][i], 3 - color);
	}
}
int main() {
	scanf("%d", &k);
	while (k--) {
		memset(check, 0, sizeof(check));
		for (int i = 0; i < MAX; i++) graph[i].clear();
		scanf("%d %d", &v, &e);
		for (int i = 0; i < e; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) if (!check[i]) dfs(i, 1);
		int res = 1;

		for (int i = 1; i <= v; i++) 
			for (int j = 0; j < graph[i].size(); j++)
				if (check[i] == check[graph[i][j]]) 
					res = 0;
		if (!res) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}