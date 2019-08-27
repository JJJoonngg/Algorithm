/*
https://www.acmicpc.net/problem/17136
문제
정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.
색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다.
1이 적힌 칸은 모두 색종이로 덮여져야 한다. 색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 겹쳐도 안 된다. 또, 칸의 경계와 일치하게 붙여야 한다.
0이 적힌 칸에는 색종이가 있으면 안 된다.

종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.

입력
총 10개의 줄에 종이의 각 칸에 적힌 수가 주어진다.

출력
모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다.
*/
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int paper[6] = { 0,0,0,0,0,0 };
int res = INF;
void dfs(int y, int x, int siz, int ans, vector<vector<int>> MAP) {
	if (ans > res) return;
	//가능 한지 아닌지 check
	bool check = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (MAP[i][j] == 1) {
				check = true;
				break;
			}
		}
		if (check) break;
	}

	//불가시 값 계산하고 넘겨주기
	if (!check) {
		res = min(res, ans - 1);
		if (res == -1) res = 0;
		return;
	}

	//범위내에 없앨 것 찾기 도중에 아니면 그냥 return
	for (int i = y; i < y + siz; i++) {
		for (int j = x; j < x + siz; j++) {
			if (i >= 10 || j >= 10 || MAP[i][j] == 0) return;
			MAP[i][j] = 0;
		}
	}

	//새롭게 사각형 둘 곳 찾기
	int newX, newY;
	bool flag = false;
	for (newX = 0; newX < 10; newX++) {
		for (newY = 0; newY < 10; newY++) {
			if (MAP[newY][newX] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	//큰거 부터 놓고 백트래킹
	for (int siz_ = 5; siz_ >= 1; siz_--) {
		if (paper[siz_] == 5) continue;
		paper[siz_]++;
		dfs(newY, newX, siz_, ans + 1, MAP);
		paper[siz_]--;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> MAP(10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int input; cin >> input;
			MAP[i].push_back(input);
		}
	}
	dfs(0, 0, 0, 0, MAP);
	if (res == INF) res = -1;
	cout << res << "\n";
}