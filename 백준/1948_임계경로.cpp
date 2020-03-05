/*
https://www.acmicpc.net/problem/1948
����
���� ����� ��� ���ΰ� �Ϲ������� �����̰�, ����Ŭ�� ����. �׷��� � ������ ���� ������� ���� ������ ������ �׸��� ���ؼ�, � ���� ���÷κ��� ���� ���ñ��� ����� �Ͽ� ������ ��� ��θ� Ž���Ѵٰ� �Ѵ�.

�� ������ �׸��� ������� ���̰� �ʹ� ���Ƽ� ������ �׸��� ���� �� ��ġ�� ���� ���ÿ��� ��� �� ������� �Ͽ���. �׷��ٰ� �Ͽ��� �� �̵��� ������ �ð��� ��� ���÷κ��� ����� �� �ּ� �� �ð� �Ŀ� ���� �� �ִ°�? ��, �������� �����ϴ� ������� ������ �ϴ� �ð��� �ǹ��Ѵ�.

� ����� �� �ð��� ������ ���Ͽ� 1�е� ���� �ʰ� �޷��� �Ѵ�. �̷� ������� ������ ������ ���� ī��Ʈ �Ͽ���.

��� ���ô� ������ ���ΰ� 0���̰�, ���� ���ô� ������ ���ΰ� 0���̴�.

�Է�
ù° �ٿ� ������ ���� n(1 �� n �� 10,000)�� �־����� ��° �ٿ��� ������ ���� m(1 �� m �� 100,000)�� �־�����. �׸��� ��° �ٺ��� m+2�ٱ��� ������ ���� ������ ������ �־�����. ó������ ������ ��� ������ ��ȣ�� �־����� �� �������� ���� ������ ��ȣ, �׸��� ���������� �� ���θ� �����µ� �ɸ��� �ð��� �־�����. ���θ� �������� �ð��� 10,000���� �۰ų� ���� �ڿ����̴�.

�׸��� m+3° �ٿ��� ������ �׸��� ������� ����ϴ� ��� ���ÿ� ���� ���ð� �־�����.

��� ���ô� ��� ���÷κ��� ������ �����ϰ�, ��� ���÷κ��� ���� ���ÿ� ������ �����ϴ�.
7
9
1 2 4
1 3 2
1 4 3
2 6 3
2 7 5
3 5 1
4 6 4
5 6 2
6 7 5
1 7
���
ù° �ٿ��� �̵��� ������ �ð���, ��° �ٿ��� 1�е� ���� �ʰ� �޷��� �ϴ� ������ ���� �� ������ ����Ͽ���.
12
5

�˰��� �з� : ��������
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXI 10000 + 1
using namespace std;
struct info { int num; int cost; };
vector<info> graph[MAXI];
vector<info> Rgraph[MAXI];
int ind[MAXI] = { 0, }, dis[MAXI] = { 0, }, Rind[MAXI];
bool check[MAXI];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, _start, _end; 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int  x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y,z });
		Rgraph[y].push_back({ x,z });
		ind[y]++; Rind[x]++;
	}
	cin >> _start >> _end;
	//find longest distance
	queue<int> q;
	q.push(_start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto next : graph[cur]) {
			dis[next.num] = max(dis[next.num], dis[cur] + next.cost);
			ind[next.num]--;
			if (!ind[next.num]) q.push(next.num);
		}
	}
	//find longest path
	int res = 0;
	queue<int> qq;
	qq.push(_end);
	check[_end] = true;
	while (!qq.empty()) {
		int cur = qq.front(); qq.pop();
		for (auto next : Rgraph[cur]) {
			if (check[cur] && dis[cur] - dis[next.num] == next.cost) {
				res++; 
				check[next.num] = true;
			}
			Rind[next.num]--;
			if (!Rind[next.num]) qq.push({ next.num });
		}
	}
	cout << dis[_end] << "\n";
	cout << res << "\n";
}