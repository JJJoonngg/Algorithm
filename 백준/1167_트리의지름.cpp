/*
����
Ʈ���� �����̶�, Ʈ������ ������ �� �� ������ �Ÿ� �� ���� �� ���� ���Ѵ�. Ʈ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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

�˰��� �з� : Ʈ��
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAXI 100001
using namespace std;
struct info { int node; int weight; };
vector<info> tree[MAXI];
bool check[MAXI] = { 0, };
int v, res, lastNode;
void dfs(int node, int weight) {
	check[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int curN = tree[node][i].node;
		int curW = tree[node][i].weight;
		if (!check[curN]) {
			dfs(curN, curW + weight);
			if (curW + weight > res) {
				res = curW + weight;
				lastNode = curN;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v;
	for (int i = 0; i < v; i++) {
		int node; cin >> node;
		while (true) {
			int input, weight;
			cin >> input;
			if (input == -1) break;
			cin >> weight;
			tree[node].push_back({ input, weight });
		}
	}
	dfs(1, 0);
	memset(check, 0, sizeof(check));
	dfs(lastNode, 0);
	cout << res << "\n";
}