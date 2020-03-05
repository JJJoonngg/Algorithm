/*
https://www.acmicpc.net/problem/1743
문제
코레스코 콘도미니엄 8층은 학생들이 3끼의 식사를 해결하는 공간이다. 그러나 몇몇 비양심적인 학생들의 만행으로 음식물이 통로 중간 중간에 떨어져 있다. 
이러한 음식물들은 근처에 있는 것끼리 뭉치게 돼서 큰 음식물 쓰레기가 된다.
이 문제를 출제한 선생님은 개인적으로 이러한 음식물을 실내화에 묻히는 것을 정말 진정으로 싫어한다. 참고로 우리가 구해야 할 답은 이 문제를 낸 조교를 맞추는 것이 아니다.
통로에 떨어진 음식물을 피해가기란 쉬운 일이 아니다. 따라서 선생님은 떨어진 음식물 중에 제일 큰 음식물만은 피해 가려고 한다.

선생님을 도와 제일 큰 음식물의 크기를 구해서 “10ra"를 외치지 않게 도와주자.

입력
첫째 줄에 통로의 세로 길이 N(1 ≤ N ≤ 100)과 가로 길이 M(1 ≤ M ≤ 100) 그리고 음식물 쓰레기의 개수 K(1 ≤ K ≤ 10,000)이 주어진다. 
그리고 다음 K개의 줄에 음식물이 떨어진 좌표 (r, c)가 주어진다.

좌표 (r, c)의 r은 위에서부터, c는 왼쪽에서부터가 기준이다.
3 4 5
3 2
2 2
3 1
2 3
1 1

출력
첫째 줄에 음식물중 가장 큰 음식물의 크기를 출력하라.
4
*/
#include <iostream>
#include <algorithm>
#define MAXI 100 + 1
using namespace std;
int n, m, k, ans = 0, cnt = 0;
int arr[MAXI][MAXI] = { 0, };
bool visit[MAXI][MAXI] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool checkRange(int x, int y) { return x > 0 && x <= n && y > 0 && y <= m; }
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (checkRange(nextX, nextY) && !visit[nextX][nextY] && arr[nextX][nextY]) {
			cnt++; dfs(nextX, nextY);
		}
	}
}
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && arr[i][j]) {
				cnt = 1; dfs(i, j);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << "\n";
}