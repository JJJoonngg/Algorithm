/*
https://www.acmicpc.net/problem/1325
문제
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 
김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.

이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다. 
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다. 컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.
5 4
3 1
3 2
4 3
5 3
출력
첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.
1 2
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAXI 10000 + 1
using namespace std;
int ans = 0;
vector<int> graph[MAXI];
int res[MAXI];
bool visit[MAXI];
void dfs(int cur) {
	visit[cur] = true;
	res[cur]++;
	ans = max(ans, res[cur]);
	for (auto a : graph[cur]) 
		if (!visit[a])
			dfs(a);
}
int main() {
	cout.tie(NULL); cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] == ans)
			cout << i << " ";
	}
	cout << "\n";
}