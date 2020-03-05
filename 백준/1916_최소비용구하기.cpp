/*
https://www.acmicpc.net/problem/1916
����
N�� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� M���� ������ �ִ�.
�츮�� A��° ���ÿ��� B��° ���ñ��� ���µ� ��� ���� ����� �ּ�ȭ ��Ű���� �Ѵ�.
�׷��� A��° ���ÿ��� B��° ���ñ��� ���µ� ��� �ּҺ���� ����Ͽ���. ������ ��ȣ�� 1���� N�����̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000)�� �־����� ��° �ٿ��� ������ ���� M(1 �� M �� 100,000)�� �־�����.
�׸��� ��° �ٺ��� M+2�ٱ��� ������ ���� ������ ������ �־�����. ���� ó������ �� ������ ��� ������ ��ȣ�� �־�����.
�׸��� �� �������� �������� ���� ��ȣ�� �־����� �� �� ���� ����� �־�����. ���� ����� 0���� ũ�ų� ����, 100,000���� ���� �����̴�.
�׸��� M+3° �ٿ��� �츮�� ���ϰ��� �ϴ� ���� ������� ���ù�ȣ�� �������� ���ù�ȣ�� �־�����. ��������� �������� �� �� �ִ� ��츸 �Է����� �־�����.
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
���
ù° �ٿ� ��� ���ÿ��� ���� ���ñ��� ���µ� ��� �ּ� ����� ����Ѵ�.
4
*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define INF 1e9
#define MAXI 1001
#define node pair<long long,int>
using namespace std;
long long cost[MAXI];
struct info { int num; long long cost; };
int map[MAXI][MAXI] = { 0, };
vector<info> graph[MAXI];
int main() {
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, tmp; cin >> x >> y >> tmp;
		graph[x].push_back({ y,tmp });
	}

	for (int i = 1; i <= n; i++)cost[i] = INF;
	int start, end;
	cin >> start >> end;
	priority_queue<node, vector<node>, greater<node>> pq;
	cost[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		for (auto next : graph[curNode]) {
			if (cost[next.num] > curCost + next.cost) {
				cost[next.num] = curCost + next.cost;
				pq.push(make_pair(cost[next.num], next.num));
			}
		}
	}
	cout << cost[end] << "\n";
}