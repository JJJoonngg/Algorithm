/*
https://www.acmicpc.net/problem/2056

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	2983	1203	834	37.720%
문제
수행해야 할 작업 N개 (3 ≤ N ≤ 10000)가 있다. 각각의 작업마다 걸리는 시간(1 ≤ 시간 ≤ 100)이 정수로 주어진다.

몇몇 작업들 사이에는 선행 관계라는 게 있어서, 어떤 작업을 수행하기 위해 반드시 먼저 완료되어야 할 작업들이 있다.
이 작업들은 번호가 아주 예쁘게 매겨져 있어서, K번 작업에 대해 선행 관계에 있는(즉, K번 작업을 시작하기 전에 반드시 먼저 완료되어야 하는)
작업들의 번호는 모두 1 이상 (K-1) 이하이다. 작업들 중에는, 그것에 대해 선행 관계에 있는 작업이 하나도 없는 작업이 반드시 하나 이상 존재한다.
(1번 작업이 항상 그러하다)

모든 작업을 완료하기 위해 필요한 최소 시간을 구하여라. 물론, 서로 선행 관계가 없는 작업들은 동시에 수행 가능하다.

입력
첫째 줄에 N이 주어진다.
두 번째 줄부터 N+1번째 줄까지 N개의 줄이 주어진다. 2번째 줄은 1번 작업, 3번째 줄은 2번 작업, ..., N+1번째 줄은 N번 작업을 각각 나타낸다.
각 줄의 처음에는, 해당 작업에 걸리는 시간이 먼저 주어지고, 그 다음에 그 작업에 대해 선행 관계에 있는 작업들의 개수(0 ≤ 개수 ≤ 100)가 주어진다.
그리고 선행 관계에 있는 작업들의 번호가 주어진다.
7
5 0
1 1 1
3 1 2
6 1 1
1 2 2 4
8 2 2 4
4 3 3 5 6

출력
첫째 줄에 모든 작업을 완료하기 위한 최소 시간을 출력한다.
23

힌트
1번 작업 : 0~5  2번 작업 : 5~6
3번 작업 : 6~9  4번 작업 : 5~11
5번 작업 : 11~12 6번 작업 : 11~19
7번 작업 : 19~23
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXI 10000 + 1
using namespace std;
vector<int> v[MAXI];
queue<int> q;
int in[MAXI], cost[MAXI], res[MAXI];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		int cnt; cin >> cnt;
		while (cnt--) {
			int from; cin >> from;
			v[from].push_back(i);
			in[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
			res[i] = cost[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto a : v[cur]) {
			in[a]--;
			res[a] = max(res[a], res[cur] + cost[a]);
			if (!in[a])
				q.push(a);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, res[i]);
	cout << ans << "\n";
}