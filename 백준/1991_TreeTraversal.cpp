/*
����
���� Ʈ���� �Է¹޾� ���� ��ȸ(preorder traversal), ���� ��ȸ(inorder traversal), ���� ��ȸ(postorder traversal)�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� ���� Ʈ���� ����� ���� N(1��N��26)�� �־�����. ��° �ٺ��� N���� �ٿ� ���� �� ���� ���� ���� �ڽ� ���, ������ �ڽ� ��尡 �־�����.
����� �̸��� A���� ���ʴ�� ������ �빮�ڷ� �Ű�����, �׻� A�� ��Ʈ ��尡 �ȴ�. �ڽ� ��尡 ���� ��쿡�� .���� ǥ���ȴ�.
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
���
ù° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ�� ����� ����Ѵ�. �� �ٿ� N���� ���ĺ��� ���� ���� ����ϸ� �ȴ�.
ABDCEFG
DBAECFG
DBEGFCA
*/
#include <iostream>
using namespace std;
typedef struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
} TreeNode;

TreeNode* creatTreeNode(char insert) {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = insert;
	root->left = NULL;
	root->right = NULL;

	return root;
}
void preorder(TreeNode *root) {
	if (root == NULL) return;
	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(TreeNode *root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}
void postorder(TreeNode *root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	TreeNode* tree[26];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		tree[i] = creatTreeNode('A' + i);
	}
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') tree[a - 65]->left = tree[b - 65];
		if (c != '.')tree[a - 65]->right = tree[c - 65];
	}
	preorder(tree[0]);
	cout << endl;
	inorder(tree[0]);
	cout << endl;
	postorder(tree[0]);
	cout << endl;
}