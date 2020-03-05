/*
https://www.acmicpc.net/problem/10451
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 순열의 크기 N (2 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 순열이 주어지며, 각 정수는 공백으로 구분되어 있다.
2
8
3 2 7 8 1 4 5 6
10
2 1 3 4 5 6 7 9 10 8
출력
각 테스트 케이스마다, 입력으로 주어진 순열에 존재하는 순열 사이클의 개수를 출력한다.
3
7
*/
#include <iostream>
#include <vector>
#define MAXI 1000 + 1
using namespace std;
vector<int> v[MAXI];
bool visit[MAXI];
int res;
void dfs(int cur) {
	visit[cur] = true;
	for (auto a : v[cur])
		if (!visit[a])
			dfs(a);
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < MAXI; i++) v[i].clear(), visit[i] = false;
		res = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int input; cin >> input;
			v[i].push_back(input);
		}
		for (int i = 1; i <= n; i++) if (!visit[i]) dfs(i), res++;
		cout << res << "\n";
	}
}