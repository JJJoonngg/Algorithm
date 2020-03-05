/*
https://www.acmicpc.net/problem/5639
�Է�
Ʈ���� ���� ��ȸ�� ����� �־�����. ��忡 ����ִ� Ű�� ���� 10^6���� ���� ���� �����̴�. 
��� ���� �� �ٿ� �ϳ��� �־�����, ����� ���� 10,000�� �����̴�. ���� Ű�� ������ ���� ����.
50
30
24
5
28
45
98
52
60
���
�Է����� �־��� ���� �˻� Ʈ���� ���� ��ȸ�� ����� �� �ٿ� �ϳ��� ����Ѵ�.
5
28
24
45
30
60
52
98
50
*/
#include <iostream>
#define MAXI 1000000
using namespace std;
struct info {int left; int right; };
info tree[MAXI];
void dfs(int node) {
	if (tree[node].left) dfs(tree[node].left);
	if (tree[node].right) dfs(tree[node].right);
	cout << node << "\n";
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int root, data;
	cin >> root;
	while (cin >> data) {
		int node = root;
		while (true) {
			if (node > data) {
				if (!tree[node].left) {
					tree[node].left = data;
					break;
				}
				else node = tree[node].left;
			}
			else if (node < data) {
				if (!tree[node].right) {
					tree[node].right = data;
					break;
				}
				else node = tree[node].right;
			}
		}
	}
	dfs(root);
}