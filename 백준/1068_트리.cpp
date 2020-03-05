/*
https://www.acmicpc.net/problem/1068
입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지,
각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.
5
-1 0 0 1 1
2
출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.
2

알고리즘 분류 : 트리, 탐색, 그래프이론

자식 x -> 리프노드
자식 1 -> 해당 노드가 제거된 노드이면 리프노드이므로 개수 ++ 아니면 dfs
자식 2이상 -> 각각의 노드에 대해 dfs 수행
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