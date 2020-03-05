/*
문제
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
나이트가 이동하려고 하는 칸이 주어진다.
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다.
체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
출력
각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
5
28
0
*/
#include <bits/stdc++.h>
#define MAXI 300 + 1
using namespace std;
struct info { int y, x; };
bool arr[MAXI][MAXI];
int cnt, N;
bool checkRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }
int dy[] = { -2,-2,-1,-1,1,1,2,2 };
int dx[] = { 1,-1,2,-2,2,-2,1,-1 };
int bfs(info Start, info End) {
	memset(arr, 0, sizeof(arr));
	queue<info> q;
	q.push(Start);
	cnt = 0;
	while (!q.empty()) {
		int siz = q.size();
		while (siz--) {
			info cur = q.front(); q.pop();
			if (cur.x == End.x && cur.y == End.y) return cnt;
			for (int i = 0; i < 8; i++) {
				int x = cur.x + dx[i];
				int y = cur.y + dy[i];
				if (!checkRange(y, x)) continue;
				if (arr[y][x]) continue;
				q.push({ y,x });
				arr[y][x] = true;
			}
		}
		cnt++;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;  cin >> t;
	while (t--) {
		cin >> N; info a, b;
		cin >> a.y >> a.x >> b.y >> b.x;
		cout << bfs(a, b) << "\n";
	}
}