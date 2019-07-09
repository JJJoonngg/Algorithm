/*
����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�,
������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. 
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 0�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.
5 17

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
2

��Ʈ
�����̰� 5-10-9-18-17 ������ ���� 2�ʸ��� ������ ã�� �� �ִ�.
*/
#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 100001
using namespace std;
int visit[MAX], N, K;
queue<pair<int,int>> q;

int bfs(int n, int k) {
	visit[n] = true;
	q.push(make_pair(n,0));

	while (!q.empty()) {
		int siz = q.size();
		for (int i = 0; i < siz; i++) {
			int position = q.front().first;
			int time = q.front().second;
			q.pop();

			if (position == k) return time;

			while (position * 2 < MAX && !visit[position * 2]) {
				visit[position * 2] = true;
				q.push(make_pair(position * 2, time));
			}

			if (0 <= position - 1 && !visit[position - 1]) {
				visit[position - 1] = true;
				q.push(make_pair(position - 1, time + 1));
			}
			if (position + 1 < MAX && !visit[position + 1]) {
				visit[position + 1] = true;
				q.push(make_pair(position + 1, time + 1));
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs(N, K));
	return 0;
}