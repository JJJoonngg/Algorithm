/*
https://www.acmicpc.net/problem/1991
����
���� Ʈ���� �Է¹޾� ���� ��ȸ(preorder traversal), ���� ��ȸ(inorder traversal), ���� ��ȸ(postorder traversal)�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ��� ���� ���� ���� Ʈ���� �ԷµǸ�,

���� ��ȸ�� ��� : ABDCEFG // (��Ʈ) (���� �ڽ�) (������ �ڽ�)
���� ��ȸ�� ��� : DBAECFG // (���� �ڽ�) (��Ʈ) (������ �ڽ�)
���� ��ȸ�� ��� : DBEGFCA // (���� �ڽ�) (������ �ڽ�) (��Ʈ)
�� �ȴ�.

�Է�
ù° �ٿ��� ���� Ʈ���� ����� ���� N(1��N��26)�� �־�����. 
��° �ٺ��� N���� �ٿ� ���� �� ���� ���� ���� �ڽ� ���, ������ �ڽ� ��尡 �־�����. 
����� �̸��� A���� ���ʴ�� ������ �빮�ڷ� �Ű�����, �׻� A�� ��Ʈ ��尡 �ȴ�. �ڽ� ��尡 ���� ��쿡�� .���� ǥ���ȴ�.
7
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
struct info { char node; char left; char right; };
info tree[27];
void preorder(char node) {
	if (node == '.') return;
	else {
		cout << tree[node - 'A'].node;
		preorder(tree[node - 'A'].left);
		preorder(tree[node - 'A'].right);
	}
}
void inorder(char node) {
	if (node == '.') return;
	else {
		inorder(tree[node - 'A'].left);
		cout << tree[node - 'A'].node;
		inorder(tree[node - 'A'].right);
	}
}
void postorder(char node) {
	if (node == '.') return;
	else {
		postorder(tree[node - 'A'].left);
		postorder(tree[node - 'A'].right);
		cout << tree[node - 'A'].node;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while(n--){
		char x, y, z;
		cin >> x >> y >> z;
		tree[x - 'A'].node = x;
		tree[x - 'A'].left = y;
		tree[x - 'A'].right = z;
	}
	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A'); cout << "\n";
}