/*
https://www.acmicpc.net/problem/3176
����
N���� ���ÿ� �� ���ø� �����ϴ� N-1���� ���η� �̷���� ���� ��Ʈ��ũ�� �ִ�.
��� ������ �ֿ��� �� ���ø� �����ϴ� ������ ��ΰ� �ְ�, �� ������ ���̴� �Է����� �־�����.
�� K���� ���� ���� �־�����. �̶�, �� ���ø� �����ϴ� ��� �󿡼� ���� ª�� ������ ���̿� ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (2 �� N �� 100,000)
���� N-1�� �ٿ��� ���θ� ��Ÿ���� �� ���� A, B, C�� �־�����. A�� B���̿� ���̰� C�� ���ΰ� �ִٴ� ���̴�. ������ ���̴� 1,000,000���� �۰ų� ���� ���� �����̴�.
���� �ٿ��� K�� �־�����. (1 �� K �� 100,000)
���� K�� �ٿ��� ���� �ٸ� �� �ڿ��� D�� E�� �־�����. D�� E�� �����ϴ� ��ο��� ���� ª�� ������ ���̿� ���� �� ������ ���̸� ���ؼ� ����ϸ� �ȴ�.
5
2 3 100
4 3 200
1 5 150
1 3 50
3
2 4
3 5
1 2

���
�� K�� �ٿ� D�� E�� �����ϴ� ��ο��� ���� ª�� ������ ���̿� ���� �� ������ ���̸� ����Ѵ�.
100 200
50 150
50 100

�˰��� �з� : LCA
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXI 100000 + 1
#define INF 1e9
#define NAV -1
using namespace std;
struct info { int num; int cost; };
int n, k;
vector<info> graph[MAXI];
int parent[MAXI][21], depth[MAXI];
int maxANS[MAXI][21], minANS[MAXI][21];



//LCA�� �ϱ� ���� ��ó�� �Լ��� tree�� ����
void dfs(int cur, int p, int value) {
	depth[cur] = depth[p] + 1;
	parent[cur][0] = p;
	minANS[cur][0] = value;
	maxANS[cur][0] = value;

	for (int i = 1; i <= 20; i++)
		parent[cur][i] = parent[parent[cur][i - 1]][i - 1];

	for (auto next : graph[cur]) {
		if (next.num != p)
			dfs(next.num, cur, next.cost);
	}
}

//��Ʈ ���� ���� �� ���� ���� ����� �ּڰ��� �ִ� ���� ��ó��
void prevCalculation() {
	for (int _parent = 1; _parent <= 20; _parent++) {
		for (int _cur = 1; _cur <= n; _cur++) {
			minANS[_cur][_parent] = min(minANS[_cur][_parent - 1], minANS[parent[_cur][_parent - 1]][_parent - 1]);
			maxANS[_cur][_parent] = max(maxANS[_cur][_parent - 1], maxANS[parent[_cur][_parent - 1]][_parent - 1]);
		}
	}
}

void lca(int a, int b) {
	int minRes = INF;
	int maxRes = NAV;
	if (depth[a] != depth[b]) {
		//depth�� ���� ���� �������� depth�� ���� ������ �ݺ�
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = 20; i >= 0; i--) {
			if (depth[b] <= depth[parent[a][i]]) {
				//min �� max �� ���� �ʿ�
				//a�� parent �� �ö�
				minRes = min(minRes, minANS[a][i]);
				maxRes = max(maxRes, maxANS[a][i]);
				a = parent[a][i];
			}
		}
	}

	//lca ����
	int tmp = b;

	//depth�� ���������� lca�� ���� ���
	//������ �����带 Ÿ�� �ö󰡸� lca���� �ݺ�
	//���ó� min, max �� ���� �ʿ�
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				minRes = min(minRes, min(minANS[a][i], minANS[b][i]));
				maxRes = max(maxRes, max(maxANS[a][i], maxANS[b][i]));
				a = parent[a][i];
				b = parent[b][i];
			}
			//parent�� ã�� �ö�
			tmp = parent[b][i];
		}
	}
	//lca �ٷ� �Ʒ� ���鸸 min, max ���� �Ǿ������Ƿ�
	//a�� lca, b�� lca ������ ���鵵 ���� �ʿ�
	if (b != tmp) {
		minRes = min(minRes, min(minANS[a][0], minANS[b][0]));
		maxRes = max(maxRes, max(maxANS[a][0], maxANS[b][0]));
	}
	cout << minRes << " " << maxRes << "\n";
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	depth[0] = -1;
	dfs(1, 0, 0);
	prevCalculation();
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		lca(x, y);
	}
}

