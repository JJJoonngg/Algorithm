/*
입력
첫째 줄에 유저의 수 N (2 ≤ N ≤ 100)과 친구 관계의 수 M (1 ≤ M ≤ 5,000)이 주어진다.
둘째 줄부터 M개의 줄에는 친구 관계가 주어진다. 친구 관계는 A와 B로 이루어져 있으며, A와 B가 친구라는 뜻이다.
A와 B가 친구이면, B와 A도 친구이며, A와 B가 같은 경우는 없다. 친구 관계는 중복되어 들어올 수도 있으며,
친구가 한 명도 없는 사람은 없다. 또, 모든 사람은 친구 관계로 연결되어져 있다.
5 5
1 3
1 4
4 5
4 3
3 2
출력
첫째 줄에 BOJ의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 출력한다. 그런 사람이 여러 명일 경우에는 번호가 가장 작은 사람을 출력한다.
3
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 111
using namespace std;
int N, M, min_person, min_cnt = 99999, res[MAX];
vector<vector<int>> relation(MAX);

void dfs(int depth, int person) {
	if (res[person]) res[person] = min(depth, res[person]);
	else res[person] = depth;
	for (int i = 0; i < relation[person].size(); i++) {
		int next = relation[person][i];
		if (!res[next] || res[next] > depth + 1) dfs(depth + 1, next);
	}
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		relation[x].push_back(y);
		relation[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		memset(res, 0, sizeof(res));
		for (int j = 0; j < relation[i].size(); j++) dfs(1, relation[i][j]);
		int tmp = 0;
		for (int k = 1; k <= N; k++) {
			if (k == i) continue;
			tmp += res[k];
		}
		if (min_cnt > tmp) {
			min_cnt = tmp;
			min_person = i;
		}
	}
	printf("%d\n", min_person);
	return 0;
}