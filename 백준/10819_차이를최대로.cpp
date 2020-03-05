/*
https://www.acmicpc.net/problem/10819
문제
N개의 정수로 이루어진 배열 A가 주어진다.
이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다.
배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.
6
20 1 15 4 10 8

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.
62

브루트 포스,  DFS
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, res = 0;
vector<int> a, b;
bool visit[9];
void cal() {
	int tmp = 0;
	for (int i = 0; i < n - 1; i++)
		tmp += abs(b[i] - b[i + 1]);
	res = max(res, tmp);
}
void dfs() {
	if (b.size() == n) cal();
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			b.push_back(a[i]);
			dfs();
			visit[i] = false;
			b.pop_back();
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n; a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	dfs();
	cout << res << "\n";
}