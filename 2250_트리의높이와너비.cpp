/*
https://www.acmicpc.net/problem/2250
문제
이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 이때 다음의 규칙에 따라 그리려고 한다.

이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
한 열에는 한 노드만 존재한다.
임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고,
오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.
이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중
가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다.
트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

아래 그림은 어떤 이진트리를 위의 규칙에 따라 그려 본 것이다.
첫 번째 레벨의 너비는 1, 두 번째 레벨의 너비는 13, 3번째, 4번째 레벨의 너비는 각각 18이고, 5번째 레벨의 너비는 13이며, 그리고 6번째 레벨의 너비는 12이다.
우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하려고 한다.
위의 그림의 예에서 너비가 가장 넓은 레벨은 3번째와 4번째로 그 너비는 18이다.
너비가 가장 넓은 레벨이 두 개 이상 있을 때는 번호가 작은 레벨을 답으로 한다. 그러므로 이 예에 대한 답은 레벨은 3이고, 너비는 18이다.
임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오

입력
첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다. 다음 N개의 줄에는
각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다. 노드들의 번호는 1부터 N까지이며,
자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.
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
출력
첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.
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
	//초기값 설정하고 for문 돌려 최댓값 갱신
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