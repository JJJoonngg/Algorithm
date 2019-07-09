/*
https://www.acmicpc.net/problem/14620
입력
입력의 첫째 줄에 화단의 한 변의 길이 N(6≤N≤10)이 들어온다.
이후 N개의 줄에 N개씩 화단의 지점당 가격(0≤G≤200)이 주어진다.
6
1 0 2 3 3 4
1 1 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1
출력
꽃을 심기 위한 최소 비용을 출력한다.
12
*/
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
bool visit[11][11] = { 0, };
int n, arr[11][11] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool checkRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
bool checkVisit(int x, int y) {
	for (int k = 0; k < 4; k++) {
		int nextX = x + dx[k];
		int nextY = y + dy[k];
		if (visit[nextX][nextY])
			return true;
	}
	return false;
}
int res = INF;
void dfs(int cnt, int sum, int x, int y) {
	if (cnt == 3) {
		res = min(res, sum);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = y; j < n - 1; j++) {
			if (visit[i][j] || !checkRange(i, j) || checkVisit(i, j)) continue;
			int tmp = arr[i][j];
			visit[i][j] = true;
			for (int k = 0; k < 4; k++) {
				int nextX = i + dx[k];
				int nextY = j + dy[k];
				visit[nextX][nextY] = true;
				tmp += arr[nextX][nextY];
			}
			dfs(cnt + 1, sum + tmp, i, j);
			visit[i][j] = false;
			for (int k = 0; k < 4; k++) {
				int nextX = i + dx[k];
				int nextY = j + dy[k];
				visit[nextX][nextY] = false;
			}
		}
	}
}
int main() {
	cout.tie(NULL); cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	dfs(0, 0, 1, 1);
	cout << res << "\n";
}