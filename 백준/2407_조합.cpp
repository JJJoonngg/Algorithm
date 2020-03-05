/*
https://www.acmicpc.net/problem/2407
문제
nCm을 출력한다.

입력
n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)
100 6
출력
nCm을 출력한다.
1192052400
*/
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100 + 1
using namespace std;
string dp[MAX][MAX];
string bigINT(string x, string y) {
	long long sum = 0;
	string res;
	while (!x.empty() || !y.empty() || sum) {
		if (!x.empty()) {
			sum += x.back() - '0';
			x.pop_back();
		}
		if (!y.empty()) {
			sum += y.back() - '0';
			y.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
string combination(int n, int m) {
	if (n == m || m == 0) return "1";

	string &res = dp[n][m];
	if (res != "") return res;

	res = bigINT(combination(n - 1, m - 1), combination(n - 1, m));
	return res;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	cout << combination(n, m) << "\n";
}