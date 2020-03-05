/*
문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
7
1 6
6 3
3 5
4 1
2 4
4 7

12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

4
6
1
3
1
4

1
1
2
3
3
4
4
5
5
6
6
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int parent[100001] = { 0 , }; //root노드는 부모 x
bool visit[100001] = { 1, };
vector<int> tree[100001];
queue<int> q;
int N;
void bfs(int root) {
	//초기값 1
	q.push(root);
	while (!q.empty()) {
		//연결노드 이용
		int node = q.front();
		q.pop();
		//해당 노드에 연결된 노드 찾아감
		for (auto a : tree[node]) {
			//연결노드 방문하고, 부모설정
			if (!visit[a]) {
				visit[a] = true;
				parent[a] = node;
				q.push(a);
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		//vector 양방향 연결
	}
	//bfs 시작
	bfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}