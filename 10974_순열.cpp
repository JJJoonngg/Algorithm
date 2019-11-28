/*
https://www.acmicpc.net/problem/10974
문제
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.
3
출력
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
bool visit[9];
void dfs() {
	if (v.size() == n) {
		for (int i = 0; i < n; i++)
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
	cin >> n;
	dfs();
}