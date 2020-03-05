/*
https://www.acmicpc.net/problem/11725
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
#define MAXI 100000 + 1
using namespace std;
int parent[MAXI];
bool visit[MAXI];
int n;
vector<int> tree[MAXI];
queue<int> q;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	parent[1] = 0;
	visit[1] = true;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto a : tree[node]) {
			if (!visit[a]) {
				visit[a] = true;
				parent[a] = node;
				q.push(a);
			}
		}
	}
	for (int i = 2; i <= n; i++)cout << parent[i] << "\n";
}