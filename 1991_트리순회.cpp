/*
https://www.acmicpc.net/problem/1991
문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 
둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현된다.
7
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