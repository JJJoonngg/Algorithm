/*
����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�,
������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�.
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ �׸���,
���� ���� �ð����� ã�� ����� �� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.
5 17
���
ù° �ٿ� �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
��° �ٿ��� ���� ���� �ð����� �����̰� ������ ã�� ����� ���� ����Ѵ�.
4
2
*/
#include <iostream>
#include <queue>
#include <cstdio>
#define MAX 100001
using namespace std;
queue < pair<int, int>> q;
int N, K, cnt, minTime, visit[MAX];

int bfs(int n, int k) {
	cnt = 0, minTime = 0;
	q.push(make_pair(n, 0));
	visit[n] = true;

	while (!q.empty()) {
		int position = q.front().first;
		int time = q.front().second;
		q.pop();
		visit[position] = true;

		if (minTime > 0 && minTime == time && position == k)
			cnt++;
		if (!minTime && position == k) {
			minTime = time;
			cnt++;
		}
		if (position + 1 < MAX && !visit[position + 1])
			q.push(make_pair(position + 1, time + 1));
		if (position - 1 >= 0 && !visit[position - 1])
			q.push(make_pair(position - 1, time + 1));
		if (position * 2 < MAX && !visit[position * 2])
			q.push(make_pair(position * 2, time + 1));
	}
	return minTime;
}
int main() {
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs(N, K));
	printf("%d\n", cnt);
	return 0;
}