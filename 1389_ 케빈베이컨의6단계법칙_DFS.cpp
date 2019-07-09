/*
�Է�
ù° �ٿ� ������ �� N (2 �� N �� 100)�� ģ�� ������ �� M (1 �� M �� 5,000)�� �־�����.
��° �ٺ��� M���� �ٿ��� ģ�� ���谡 �־�����. ģ�� ����� A�� B�� �̷���� ������, A�� B�� ģ����� ���̴�.
A�� B�� ģ���̸�, B�� A�� ģ���̸�, A�� B�� ���� ���� ����. ģ�� ����� �ߺ��Ǿ� ���� ���� ������,
ģ���� �� �� ���� ����� ����. ��, ��� ����� ģ�� ����� ����Ǿ��� �ִ�.
5 5
1 3
1 4
4 5
4 3
3 2
���
ù° �ٿ� BOJ�� ���� �߿��� �ɺ� �������� ���� ���� ���� ����� ����Ѵ�. �׷� ����� ���� ���� ��쿡�� ��ȣ�� ���� ���� ����� ����Ѵ�.
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