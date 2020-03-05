/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)
8

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다
92
알고리즘 분류 : 백트레킹
*/
#include <bits/stdc++.h>
#define MAXI 32
using namespace std;
int n;
bool row[MAXI];
bool positiveDiagonal[MAXI];
bool negativeDiagonal[MAXI];
int res = 0;
void dfs(int col) {
	if (col == n) {
		res++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!row[i] && !positiveDiagonal[col + i] && !negativeDiagonal[n + col - i]) {
				row[i] = positiveDiagonal[col + i] = negativeDiagonal[n + col - i] = true;
				dfs(col + 1);
				row[i] = positiveDiagonal[col + i] = negativeDiagonal[n + col - i] = false;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(0);
	cout << res << "\n";
}