/*
https://www.acmicpc.net/problem/2250
����
����Ʈ���� ������ ��Ģ�� ���� ��� ���� ��ȣ�� �پ��ִ� ���� ����� Ʋ �ӿ� �׸����� �Ѵ�. �̶� ������ ��Ģ�� ���� �׸����� �Ѵ�.

����Ʈ������ ���� ����(level)�� �ִ� ���� ���� �࿡ ��ġ�Ѵ�.
�� ������ �� ��常 �����Ѵ�.
������ ����� ���� ��Ʈ��(left subtree)�� �ִ� ������ �ش� ��庸�� ������ ���� ��ġ�ϰ�,
������ ��Ʈ��(right subtree)�� �ִ� ������ �ش� ��庸�� �������� ���� ��ġ�Ѵ�.
��尡 ��ġ�� ���� ���� ���� ������ �� ���̿� �ƹ� ��嵵 ���� ����ִ� ���� ����.
�̿� ���� ��Ģ�� ���� ����Ʈ���� �׸� �� �� ������ �ʺ�� �� ������ �Ҵ�� ��� ��
���� �����ʿ� ��ġ�� ����� �� ��ȣ���� ���� ���ʿ� ��ġ�� ����� �� ��ȣ�� �� �� ���ϱ� 1�� �����Ѵ�.
Ʈ���� ������ ���� ���ʿ� �ִ� ��Ʈ ��尡 1�̰� �Ʒ��� 1�� �����Ѵ�.

�Ʒ� �׸��� � ����Ʈ���� ���� ��Ģ�� ���� �׷� �� ���̴�.
ù ��° ������ �ʺ�� 1, �� ��° ������ �ʺ�� 13, 3��°, 4��° ������ �ʺ�� ���� 18�̰�, 5��° ������ �ʺ�� 13�̸�, �׸��� 6��° ������ �ʺ�� 12�̴�.
�츮�� �־��� ����Ʈ���� ���� ��Ģ�� ���� �׸� ���� �ʺ� ���� ���� ������ �� ������ �ʺ� ����Ϸ��� �Ѵ�.
���� �׸��� ������ �ʺ� ���� ���� ������ 3��°�� 4��°�� �� �ʺ�� 18�̴�.
�ʺ� ���� ���� ������ �� �� �̻� ���� ���� ��ȣ�� ���� ������ ������ �Ѵ�. �׷��Ƿ� �� ���� ���� ���� ������ 3�̰�, �ʺ�� 18�̴�.
������ ����Ʈ���� �Է����� �־��� �� �ʺ� ���� ���� ������ �� ������ �ʺ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�

�Է�
ù° �ٿ� ����� ������ ��Ÿ���� ���� N(1 �� N �� 10,000)�� �־�����. ���� N���� �ٿ���
�� �ٸ��� ��� ��ȣ�� �ش� ����� ���� �ڽ� ���� ������ �ڽ� ����� ��ȣ�� ������� �־�����. ������ ��ȣ�� 1���� N�����̸�,
�ڽ��� ���� ��쿡�� �ڽ� ����� ��ȣ�� -1�� �־�����.
19
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1
���
ù° �ٿ� �ʺ� ���� ���� ������ �� ������ �ʺ� ������� ����Ѵ�. �ʺ� ���� ���� ������ �� �� �̻� ���� ������ ��ȣ�� ���� ������ ����Ѵ�.
3 18
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXI 10001
#define INF 987654321
using namespace std;
int n, nodeIdx = 1, root;
int node[MAXI] = { 0, }, low[MAXI] = { 0, }, high[MAXI] = { 0, };
struct info { int left; int right; };
vector<info> tree;
//Inorder
void dfs(int nodeNum, int cnt) {

	//left subtree
	if (tree[nodeNum].left > 0)
		dfs(tree[nodeNum].left, cnt + 1);

	//visit
	low[cnt] = min(low[cnt], nodeIdx);
	high[cnt] = max(high[cnt], nodeIdx++);

	//right subtree
	if (tree[nodeNum].right > 0)
		dfs(tree[nodeNum].right, cnt + 1);

}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; tree.resize(n + 1);
	for (int i = 0; i < MAXI; i++) low[i] = INF;
	for (int i = 0; i < n; i++) {
		int parent, Lchild, Rchild;
		cin >> parent >> Lchild >> Rchild;
		node[parent]++;
		if (Lchild != -1) node[Lchild]++;
		if (Rchild != -1)node[Rchild]++;
		tree[parent].left = Lchild;
		tree[parent].right = Rchild;
	}
	for (int i = 1; i <= n; i++)
		if (node[i] == 1) {
			root = i;
			break;
		}
	dfs(root, nodeIdx);
	//�ʱⰪ �����ϰ� for�� ���� �ִ� ����
	int res = high[1] - low[1] + 1;
	int level = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = high[i] - low[i] + 1;
		if (tmp > res) {
			res = tmp;
			level = i;
		}
	}
	cout << level << " " << res << "\n";
}