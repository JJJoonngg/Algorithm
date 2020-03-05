/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고,
동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고,
가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
5 17
출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다.
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