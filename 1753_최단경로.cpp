/*
https://www.acmicpc.net/problem/1753
����
����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, ��� ������ ����ġ�� 10 ������ �ڿ����̴�.

�Է�
ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����. (1��V��20,000, 1��E��300,000) ��� �������� 1���� V���� ��ȣ�� �Ű��� �ִٰ� �����Ѵ�.
��° �ٿ��� ���� ������ ��ȣ K(1��K��V)�� �־�����. ��° �ٺ��� E���� �ٿ� ���� �� ������ ��Ÿ���� �� ���� ���� (u, v, w)�� ������� �־�����.
�̴� u���� v�� ���� ����ġ w�� ������ �����Ѵٴ� ���̴�. u�� v�� ���� �ٸ��� w�� 10 ������ �ڿ����̴�. ���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ������ �����Ѵ�.
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
���
ù° �ٺ��� V���� �ٿ� ����, i��° �ٿ� i�� ���������� �ִ� ����� ��ΰ��� ����Ѵ�. ������ �ڽ��� 0���� ����ϰ�, ��ΰ� �������� �ʴ� ��쿡�� INF�� ����ϸ� �ȴ�.
0
2
3
7
INF
*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define INF 1e9
#define MAXI 20001
#define node pair<int, int>
using namespace std;
struct info { int num; int cost; };
vector<info> graph[MAXI];
int cost[MAXI] = { 0, };
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int x, y, tmp;
		cin >> x >> y >> tmp;
		graph[x].push_back({ y,tmp });
	}
	for (int i = 1; i <= v; i++) cost[i] = INF;
	cost[k] = 0;
	priority_queue<node, vector<node>, greater<node>> pq;
	pq.push(make_pair(cost[k], k));
	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		for (auto next : graph[curNode]) {
			if (curCost + next.cost < cost[next.num]) {
				cost[next.num] = curCost + next.cost;
				pq.push(make_pair(cost[next.num], next.num));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (cost[i] == INF) cout << "INF\n";
		else cout << cost[i] << "\n";
	}
}