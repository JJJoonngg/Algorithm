/*
����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�,
������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. 
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. 
�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.
5 17

5 17
���
ù° �ٿ� �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
��° �ٿ� ��� �̵��ؾ� �ϴ��� �������� ������ ����Ѵ�.
4
5 10 9 18 17

4
5 4 8 16 17
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int N, K, visit[MAX],parent[MAX];
queue<int> q;
vector<int> v;
int bfs(int n, int k) {
	visit[n] = true;
	q.push(n);
	int time = 0;
	while (!q.empty()) {
		int siz = q.size();
		while(siz--) {
			int position = q.front();
			q.pop();

			if (position == k) {
				int tmp = position;
				while (tmp != n) {
					v.push_back(tmp);
					tmp = parent[tmp];
				}
				v.push_back(n);
				return time;
			}
			
			if (position * 2 < MAX && !visit[position * 2]) {
				visit[position * 2] = true;
				parent[position * 2] = position;
				q.push(position * 2);
			}
			if (position + 1 < MAX && !visit[position + 1]) {
				visit[position + 1] = true;
				parent[position + 1] = position;
				q.push(position + 1);
			}
			if (position - 1 >= 0 && !visit[position - 1]) {
				visit[position - 1] = true;
				parent[position - 1] = position;
				q.push(position - 1);
			}
		}
		time++;
	}
}
int main() {
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs(N, K));
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}