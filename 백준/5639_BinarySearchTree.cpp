/*
����
���� �˻� Ʈ���� ������ ���� �� ���� ������ �����ϴ� ���� Ʈ���̴�.
����� ���� ����Ʈ���� �ִ� ��� ����� Ű�� ����� Ű���� �۴�.
����� ������ ����Ʈ���� �ִ� ��� ����� Ű�� ����� Ű���� ũ��.
����, ������ ����Ʈ���� ���� �˻� Ʈ���̴�.

���� ��ȸ (��Ʈ-����-������)�� ��Ʈ�� �湮�ϰ�, ���� ����Ʈ��, ������ ���� Ʈ���� ������� �湮�ϸ鼭 ����� Ű�� ����Ѵ�. 
���� ��ȸ (����-������-��Ʈ)�� ���� ����Ʈ��, ������ ����Ʈ��, ��Ʈ ��� ������� Ű�� ����Ѵ�. 
���� ���, ���� ���� �˻� Ʈ���� ���� ��ȸ ����� 50 30 24 5 28 45 98 52 60 �̰�, ���� ��ȸ ����� 5 28 24 45 30 60 52 98 50 �̴�.

���� �˻� Ʈ���� ���� ��ȸ�� ����� �־����� ��, �� Ʈ���� ���� ��ȸ�� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
Ʈ���� ���� ��ȸ�� ����� �־�����. ��忡 ����ִ� Ű�� ���� 106���� ���� ���� �����̴�.
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
using namespace std;
typedef struct BST{
	int left = 0;
	int right = 0;
}Tree;
Tree tree[1000000];

void postorder(int node) {
	if (tree[node].left != 0) postorder(tree[node].left);
	if (tree[node].right != 0) postorder(tree[node].right);
	cout << node << "\n";
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int root;
	int data;
	//preorder first data is root node
	cin >> root;

	while (cin >> data) {
		int node = root;
		while (true) {
			if (node > data) {
				if (tree[node].left == 0) {
					tree[node].left = data;
					break;
				}
				else {
					node = tree[node].left;
				}
			}
			else if (node < data) {
				if (tree[node].right == 0) {
					tree[node].right = data;
					break;
				}
				else {
					node = tree[node].right;
				}
			}
		}
	}
	//print postorder result
	postorder(root);

	return 0;
}