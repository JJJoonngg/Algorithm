/*
https://www.acmicpc.net/problem/15650
����
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�� ������ ���������̾�� �Ѵ�.

�Է�
ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)
3 1
4 2
4 4
���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ������ ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.
1
2
3

1 2
1 3
1 4
2 3
2 4
3 4

1 2 3 4
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<bool> visit;
vector<int> v;
void dfs(int cnt) {
	if (v.size() == m) {
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = cnt; i <= n; i++) {
		if (v.size() < m) {
			v.push_back(i);
			dfs(i + 1);
			v.pop_back();
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	visit.resize(n + 1);
	dfs(1);
}