/*
����
��Ʈ ���� Ʈ���� �־�����. �̶�, Ʈ���� ��Ʈ�� 1�̶�� ������ ��, �� ����� �θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� ���� N (2 �� N �� 100,000)�� �־�����. ��° �ٺ��� N-1���� �ٿ� Ʈ�� �󿡼� ����� �� ������ �־�����.
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

���
ù° �ٺ��� N-1���� �ٿ� �� ����� �θ� ��� ��ȣ�� 2�� ������ ������� ����Ѵ�.

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
int parent[100001] = { 0 , }; //root���� �θ� x
bool visit[100001] = { 1, };
vector<int> tree[100001];
queue<int> q;
int N;
void bfs(int root) {
	//�ʱⰪ 1
	q.push(root);
	while (!q.empty()) {
		//������ �̿�
		int node = q.front();
		q.pop();
		//�ش� ��忡 ����� ��� ã�ư�
		for (auto a : tree[node]) {
			//������ �湮�ϰ�, �θ���
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
		//vector ����� ����
	}
	//bfs ����
	bfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}