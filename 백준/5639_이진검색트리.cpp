/*
https://www.acmicpc.net/problem/5639
입력
트리를 전위 순회한 결과가 주어진다. 노드에 들어있는 키의 값은 10^6보다 작은 양의 정수이다. 
모든 값은 한 줄에 하나씩 주어지며, 노드의 수는 10,000개 이하이다. 같은 키를 가지는 노드는 없다.
50
30
24
5
28
45
98
52
60
출력
입력으로 주어진 이진 검색 트리를 후위 순회한 결과를 한 줄에 하나씩 출력한다.
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