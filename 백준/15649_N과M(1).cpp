/*
https://www.acmicpc.net/problem/15649
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
3 1
4 2
4 4
출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
1
2
3

1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3

1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<bool> visit;
vector<int> v;
void dfs() {
	if (v.size() == m){
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true; v.push_back(i);
			dfs();
			visit[i] = false; v.pop_back();
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	visit.resize(n + 1);
	dfs();
}