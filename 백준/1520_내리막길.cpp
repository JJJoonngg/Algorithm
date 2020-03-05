/*
https://www.acmicpc.net/problem/1520
����
������ �־��� �� �̿� ���� ���� ���� �� �������� ����Ͽ� ���� ������ �Ʒ� �������� 
�׻� ��������θ� �̵��ϴ� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� ������ ������ ũ�� M�� ������ ũ�� N�� ��ĭ�� ���̿� �ΰ� �־�����. 
�̾� ���� M�� �ٿ� ���� �� �ٿ� N���� ���������� ���ʷ� �� ������ ���̰� �� ĭ�� ���̿� �ΰ� �־�����.
M�� N�� ���� 500������ �ڿ����̰�, �� ������ ���̴� 10000������ �ڿ����̴�.
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
���
ù° �ٿ� �̵� ������ ����� �� H�� ����Ѵ�. ��� �Է¿� ���Ͽ� H�� 10�� ������ ���� �ƴ� �����̴�.
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