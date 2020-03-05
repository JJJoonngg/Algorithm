/*
입력
첫 번째 줄에 N(3≤N≤100,000)과 M(1≤M≤1,000,000)이 주어진다. N은 CTP에 존재하는 도시의 개수를 의미하고 M은 CTP에 존재하는 튜브의 개수를 의미한다. 다음 M개의 줄에 걸쳐 X, Y(1≤X, Y≤N)가 주어지는데 X에서 Y로 이동할 수 있는 튜브가 있다는 뜻이다. 다음 줄에는 시나리오의 개수 T(1≤T≤100,000)가 주어진다. 다음 T개의 줄에 차례대로 C(2≤C≤N-1)가 주어지는데 이는 우주급 빌런 재유니스가 반물질 폭탄을 설치한 도시의 번호를 의미한다. 입/출력의 양이 많으므로 속도가 빠른 입/출력 함수를 사용하는것을 권장한다.
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
출력
T개의 줄에 걸쳐 CTP를 지킬 수 있는지 결과를 출력한다. 만약 CTP를 구할 방법이 없다면 “Destroyed the CTP”를 출력하고 슈퍼히어로 미노가 CTP를 구할 수 있다면 “Defend the CTP”를 출력한다. 모든 출력은 쌍따옴표를 제외하고 출력한다.
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