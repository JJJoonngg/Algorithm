/*
https://www.acmicpc.net/problem/1325
����
��Ŀ �������� �� �˷��� ��� ȸ�縦 ��ŷ�Ϸ��� �Ѵ�. �� ȸ��� N���� ��ǻ�ͷ� �̷���� �ִ�. 
�������� ������ ������, �� ���� ��ŷ���� ���� ���� ��ǻ�͸� ��ŷ �� �� �ִ� ��ǻ�͸� ��ŷ�Ϸ��� �Ѵ�.
�� ȸ���� ��ǻ�ʹ� �ŷ��ϴ� �����, �ŷ����� �ʴ� ����� �̷���� �ִµ�, A�� B�� �ŷ��ϴ� ��쿡�� B�� ��ŷ�ϸ�, A�� ��ŷ�� �� �ִٴ� �Ҹ���.

�� ȸ���� ��ǻ���� �ŷ��ϴ� ���谡 �־����� ��, �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ�, N�� M�� ���´�. N�� 10,000���� �۰ų� ���� �ڿ���, M�� 100,000���� �۰ų� ���� �ڿ����̴�. 
��° �ٺ��� M���� �ٿ� �ŷ��ϴ� ���谡 A B�� ���� �������� ������, "A�� B�� �ŷ��Ѵ�"�� �ǹ��Ѵ�. ��ǻ�ʹ� 1������ N������ ��ȣ�� �ϳ��� �Ű��� �ִ�.
5 4
3 1
3 2
4 3
5 3
���
ù° �ٿ�, �������� �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ������������ ����Ѵ�.
1 2
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAXI 10000 + 1
using namespace std;
int ans = 0;
vector<int> graph[MAXI];
int res[MAXI];
bool visit[MAXI];
void dfs(int cur) {
	visit[cur] = true;
	res[cur]++;
	ans = max(ans, res[cur]);
	for (auto a : graph[cur]) 
		if (!visit[a])
			dfs(a);
}
int main() {
	cout.tie(NULL); cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] == ans)
			cout << i << " ";
	}
	cout << "\n";
}