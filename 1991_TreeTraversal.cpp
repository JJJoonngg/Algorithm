/*
문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현된다.
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
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