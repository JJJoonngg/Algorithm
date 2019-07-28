/*
https://www.acmicpc.net/problem/1516
����
�� ȸ�翡�� �̹��� ���ο� ���� �ùķ��̼� ���� ���� ũ����Ʈ�� �����ϱ�� �Ͽ���. 
�ٽ����� �κ��� ������ ���� ���°�, ������ ������ ��ü ���� �ð� ���� �����ϴ� �κи� ���� �־���.
���� �÷��̿� ���� �ð��� ��Ȳ�� ���� �ٸ� �� �ֱ� ������, ��� �ǹ��� ���µ� �ɸ��� �ּ��� �ð��� �̿��Ͽ� �ٻ��ϱ�� �Ͽ���. 
����, � �ǹ��� ���� ���ؼ� �ٸ� �ǹ��� ���� ����� �� ���� �ֱ� ������ ������ �ܼ��������� ���� ���� �ִ�. 
���� ��� ��Ÿũ����Ʈ���� ��Ŀ�� ���� ���ؼ��� �跰�� ���� ����� �ϱ� ������, �跰�� ���� ���� �� ��Ŀ�� ����� �Ѵ�.

���ǻ� �ڿ��� ������ ���� ������ �ְ�, �ǹ��� ���� ����� ����������� �ð��� �ɸ��� �ʴ´ٰ� ��������.

�Է�
ù° �ٿ� �ǹ��� ���� �� N(1 �� N �� 500)�� �־�����. 
���� N���� �ٿ��� �� �ǹ��� ���µ� �ɸ��� �ð��� �� �ǹ��� ���� ���� ���� �������� �ϴ� �ǹ����� ��ȣ�� �־�����. 
�ǹ��� ��ȣ�� 1���� N������ �ϰ�, �� ���� -1�� �����ٰ� ����. �� �ǹ��� ���µ� �ɸ��� �ð��� 100,000���� �۰ų� ���� �ڿ����̴�.
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1
���
N���� �� �ǹ��� �ϼ��Ǳ���� �ɸ��� �ּ� �ð��� ����Ѵ�.
10
20
14
18
17
�˰��� �з� : ���� ����
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define MAXI 500 + 1
using namespace std;
int ind[MAXI], cost[MAXI], res[MAXI], n;
vector<int> v[MAXI];
queue<int> q;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		while (true) {
			int input; cin >> input;
			if (input == -1) break;
			v[input].push_back(i);
			ind[i]++;
		}
	}
	for (int i = 1; i <= n; i++) if (!ind[i]) res[i] = cost[i], q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto next : v[cur]) {
			res[next] = max(res[next], res[cur] + cost[next]);
			ind[next]--;
			if (!ind[next]) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << "\n";
}