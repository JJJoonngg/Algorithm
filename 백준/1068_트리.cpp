/*
https://www.acmicpc.net/problem/1068
�Է�
ù° �ٿ� Ʈ���� ����� ���� N�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� 0�� ������ N-1�� ������,
�� ����� �θ� �־�����. ���� �θ� ���ٸ� (��Ʈ) -1�� �־�����. ��° �ٿ��� ���� ����� ��ȣ�� �־�����.
5
-1 0 0 1 1
2
���
ù° �ٿ� �Է����� �־��� Ʈ������ �Է����� �־��� ��带 ������ ��, ���� ����� ������ ����Ѵ�.
2

�˰��� �з� : Ʈ��, Ž��, �׷����̷�

�ڽ� x -> �������
�ڽ� 1 -> �ش� ��尡 ���ŵ� ����̸� ��������̹Ƿ� ���� ++ �ƴϸ� dfs
�ڽ� 2�̻� -> ������ ��忡 ���� dfs ����
*/
#include <iostream>
#include <vector>
using namespace std;
int n, delNode, root, res = 0;
vector<vector<int>> tree;
void dfs(int node) {
	if (delNode == node) return;
	int siz = tree[node].size();
	if (siz == 0) {	res++; return;}
	else if (siz == 1) { if (tree[node][0] == delNode) res++; }
	for (int i = 0; i < siz; i++) 	dfs(tree[node][i]); 
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;	tree.resize(n);
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp == -1) root = i;
		else tree[tmp].push_back(i);
	}
	cin >> delNode;
	dfs(root);
	cout << res << "\n";
}