/*
https://www.acmicpc.net/problem/1167
�Է�
Ʈ���� �Է����� �־�����. ���� ù ��° �ٿ����� Ʈ���� ������ ���� V�� �־����� (2��V��100,000)
��° �ٺ��� V���� �ٿ� ���� ������ ������ ������ ���� �־�����. (���� ��ȣ�� 1���� V���� �Ű��� �ִٰ� �����Ѵ�)

���� ���� ��ȣ�� �־�����, �̾ ����� ������ ������ �ǹ��ϴ� ������ �� ���� �־����µ�, 
�ϳ��� ������ȣ, �ٸ� �ϳ��� �� ���������� �Ÿ��̴�.
���� ��� �� ��° ���� ��� ���� 3�� ���� 1�� �Ÿ��� 2�� �������� ����Ǿ� �ְ�,
���� 4�ʹ� �Ÿ��� 3�� �������� ����Ǿ� �ִ� ���� �����ش�. �� ���� ���������� -1�� �Է����� �־�����. 
�־����� �Ÿ��� ��� 10,000 ������ �ڿ����̴�.
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
���
ù° �ٿ� Ʈ���� ������ ����Ѵ�.
11
*/
#include <iostream>
#include <vector>
#include <string.h>
#define MAXI 100001
using namespace std;
struct info { int node; int value; };
bool check[MAXI];
vector<info> tree[MAXI];
int n, res = 0 , newRoot;
void dfs(int cur, int val) {
	check[cur] = true;
	for (auto a : tree[cur]) {
		if (!check[a.node]) {
			dfs(a.node, a.value + val);
			if (res < a.value + val) {
				res = a.value + val;
				newRoot = a.node;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		int node; cin >> node;
		while(true) {
			int a, b; 
			cin >> a;
			if (a == -1) break;
			cin >> b;
			tree[node].push_back({ a,b });
		}
	}
	dfs(1, 0);
	memset(check, false, sizeof(check));
	dfs(newRoot, 0);
	cout << res << "\n";
}