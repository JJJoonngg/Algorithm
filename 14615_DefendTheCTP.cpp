/*
�Է�
ù ��° �ٿ� N(3��N��100,000)�� M(1��M��1,000,000)�� �־�����. N�� CTP�� �����ϴ� ������ ������ �ǹ��ϰ� M�� CTP�� �����ϴ� Ʃ���� ������ �ǹ��Ѵ�. ���� M���� �ٿ� ���� X, Y(1��X, Y��N)�� �־����µ� X���� Y�� �̵��� �� �ִ� Ʃ�갡 �ִٴ� ���̴�. ���� �ٿ��� �ó������� ���� T(1��T��100,000)�� �־�����. ���� T���� �ٿ� ���ʴ�� C(2��C��N-1)�� �־����µ� �̴� ���ֱ� ���� �����Ͻ��� �ݹ��� ��ź�� ��ġ�� ������ ��ȣ�� �ǹ��Ѵ�. ��/����� ���� �����Ƿ� �ӵ��� ���� ��/��� �Լ��� ����ϴ°��� �����Ѵ�.
6 8
1 3
5 4
3 5
4 6
1 2
3 2
3 4
4 2
3
5
4
2
���
T���� �ٿ� ���� CTP�� ��ų �� �ִ��� ����� ����Ѵ�. ���� CTP�� ���� ����� ���ٸ� ��Destroyed the CTP���� ����ϰ� ��������� �̳밡 CTP�� ���� �� �ִٸ� ��Defend the CTP���� ����Ѵ�. ��� ����� �ֵ���ǥ�� �����ϰ� ����Ѵ�.
Defend the CTP
Defend the CTP
Destroyed the CTP
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#define MAXI 100000 + 1
using namespace std;
int n, m, t;
vector<int> v[2][MAXI];
bool visit[2][MAXI] = { 0, };
void dfs(int idx, int cur) {
	visit[idx][cur] = true;
	for (auto a : v[idx][cur]) {
		if (!visit[idx][a])
			dfs(idx, a);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		v[0][x].push_back(y);
		v[1][y].push_back(x);
	}
	dfs(0, 1);	dfs(1, n);
	scanf("%d", &t);
	while (t--) {
		int input; scanf("%d", &input);
		if (visit[0][input] && visit[1][input]) printf("Defend the CTP\n");
		else printf("Destroyed the CTP\n");
	}
}