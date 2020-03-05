/*
https://www.acmicpc.net/problem/1520
문제
지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 
항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다. 
이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다.
M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
출력
첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.
3
*/
//Bottom-up
//#include <iostream>
//#include <string.h>
//#define MAXI 500 + 1
//using namespace std;
//int dx[] = { 0,0,1,-1 };
//int dy[] = { -1,1,0,0 };
//int map[MAXI][MAXI];
//int dp[MAXI][MAXI];
//int n, m;
//bool checkRange(int x, int y) { return 0 < x && x <= n && 0 < y && y <= m; }
//int dfs(int x, int y) {
//	if (dp[x][y] != -1) return dp[x][y];
//	if (!checkRange(x, y)) return 0;
//	if (x == 1 && y == 1) return 1;
//	dp[x][y] = 0;
//	for (int i = 0; i < 4; i++) {
//		int nextX = x + dx[i];
//		int nextY = y + dy[i];
//		if (map[nextX][nextY] > map[x][y]) {
//			dp[x][y] += dfs(nextX, nextY);
//		}
//	}
//	return dp[x][y];
//}
//int main() {
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> map[i][j];
//	memset(dp, -1, sizeof(dp));
//	cout << dfs(n, m) << "\n";
//}

//Top-down
#include <iostream>
#include <string.h>
#define MAXI 500 + 1
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int map[MAXI][MAXI];
int dp[MAXI][MAXI];
int n, m;
bool checkRange(int x, int y) { return 0 < x && x <= n && 0 < y && y <= m; }
int dfs(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if (!checkRange(x, y)) return 0;
	if (x == n && y == m) return 1;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (map[nextX][nextY] < map[x][y]) {
			dp[x][y] += dfs(nextX, nextY);
		}
	}
	return dp[x][y];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 1) << "\n";
}