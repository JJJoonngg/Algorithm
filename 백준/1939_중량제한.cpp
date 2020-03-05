/*
https://www.acmicpc.net/problem/1939

����
N(2��N��10,000)���� ������ �̷���� ���� �ִ�. �̵� �� �� ���� �� ���̿��� �ٸ��� ��ġ�Ǿ� �־ ������ �ٴ� �� �ִ�.
���� �߰��������� �� ���� ���� ������ ���� �ΰ� ��ǰ�� �����ϴ� ���� �ϰ� �ִ�. ��ǰ�� �����ϴ� ���� ���忡�� �ٸ� �������� ���� ���̴� ��ǰ�� �����ؾ� �� ���� ����� �Ѵ�. 
�׷��� ������ �ٸ����� �߷������� �ֱ� ������ ���δ�� ��ǰ�� �ű� �� ����. ���� �߷������� �ʰ��ϴ� ���� ��ǰ�� �ٸ��� ������ �Ǹ� �ٸ��� �������� �ȴ�.

�� ���� �̵����� �ű� �� �ִ� ��ǰ���� �߷��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N, M(1��M��100,000)�� �־�����. ���� M���� �ٿ��� �ٸ��� ���� ������ ��Ÿ���� �� ���� A, B(1��A, B��N), C(1��C��1,000,000,000)�� �־�����. 
�̴� A�� ���� B�� �� ���̿� �߷������� C�� �ٸ��� �����Ѵٴ� �ǹ��̴�. ���� ���� �� ���� ���̿� ���� ���� �ٸ��� ���� ���� ������,
��� �ٸ��� ������̴�. ������ �ٿ��� ������ ��ġ�� �ִ� ���� ��ȣ�� ��Ÿ���� ���� �ٸ� �� ������ �־�����.
������ �ִ� �� ���� �����ϴ� ��δ� �׻� �����ϴ� �����͸� �Է����� �־�����.
3 3
1 2 2
3 1 3
2 3 2
1 3
���
ù° �ٿ� ���� ����Ѵ�.
3
�˰��� �з� : BFS, �̺�Ž��
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAXI 10000 + 1
using namespace std;
struct info { int num, limit; };
int n, m, maxCost = -1;
int __start, _end;
vector<info> island[MAXI];
bool visit[MAXI];
bool bfs(int cost) {
	memset(visit, false, sizeof(visit));
	visit[__start] = true;
	queue<int> q;
	q.push(__start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == _end) return true;
		for (auto next : island[cur]) {
			if (!visit[next.num] && cost <= next.limit)
				visit[next.num] = true, q.push(next.num);
		}
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, value;
		cin >> from >> to >> value;
		island[from].push_back({ to, value });
		island[to].push_back({ from, value });
		maxCost = max(maxCost, value);
	}

	cin >> __start >> _end;

	int s = 0, e = maxCost;

	while (s<=e) {
		int mid = (s + e) / 2;
		if (bfs(mid)) s = mid + 1;
		else e = mid - 1;
	}
	cout << e << "\n";
}