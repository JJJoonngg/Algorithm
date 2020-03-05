/*
https://www.acmicpc.net/problem/2252
����
N���� �л����� Ű ������� ���� ������� �Ѵ�. �� �л��� Ű�� ���� �缭 �����ϸ� �����ϰ�����, 
������ ����� ��� �� �л��� Ű�� ���ϴ� ����� ����ϱ�� �Ͽ���. �׳����� ��� �л����� �� ���� �� ���� �ƴϰ�, �Ϻ� �л����� Ű���� ���� ���Ҵ�.
�Ϻ� �л����� Ű�� ���� ����� �־����� ��, ���� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1��N��32,000), M(1��M��100,000)�� �־�����. M�� Ű�� ���� ȸ���̴�. 
���� M���� �ٿ��� Ű�� ���� �� �л��� ��ȣ A, B�� �־�����. �̴� �л� A�� �л� B�� �տ� ���� �Ѵٴ� �ǹ��̴�.
�л����� ��ȣ�� 1������ N���̴�.
3 2
1 3
2 3

4 2
4 2
3 1
���
ù° �ٺ��� �տ������� ���� ���� ����� ����Ѵ�. ���� ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.
1 2 3
4 2 3 1
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAXI 32000 + 1
using namespace std;
vector<int> v[MAXI];
priority_queue<int> pq;
int in[MAXI] = { 0, };
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		in[y]++;
	}
	for (int i = 1; i <= n; i++) if (!in[i]) pq.push(i);
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for (int a : v[cur]) {
			in[a]--;
			if (!in[a])
				pq.push(a);
		}
	}
	cout << "\n";
}