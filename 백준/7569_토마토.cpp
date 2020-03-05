/*
https://www.acmicpc.net/problem/7569
입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다.
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다.
둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다.
즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다.
각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다.
정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 이러한 N개의 줄이 H번 반복하여 주어진다.
5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1
출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다.
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
-1
4
0
*/
#include <bits/stdc++.h>
#define MAXI 100 + 1
using namespace std;
struct info { int y, x, z; };
int cnt = 0;
int arr[MAXI][MAXI][MAXI];
int dz[] = { -1,1,0,0,0,0 };
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 0,0,0,0,-1,1 };
int m, n, h;
bool checkRange(int x, int y, int z) { return 0 <= x && x < m && 0 <= y && y < n && 0 <= z && z < h; }
queue<info> q;
int bfs() {
	int res = 1;
	if (cnt == 0) return 0;
	while (!q.empty()) {
		int siz = q.size();
		while (siz--) {
			info cur = q.front();	q.pop();
			for (int i = 0; i < 6; i++) {
				int x = cur.x + dx[i];
				int y = cur.y + dy[i];
				int z = cur.z + dz[i];
				if (!checkRange(x, y, z)) continue;
				if (arr[y][x][z] == -1 || arr[y][x][z] == 1) continue;
				q.push({ y,x,z });
				arr[y][x][z] = 1;
				cnt--;
			}
			if (cnt == 0) return res;
		}
		res++;
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) q.push({ i,j,k });
				else if (arr[i][j][k] == 0)cnt++;
			}
		}
	}
	cout << bfs() << "\n";
}