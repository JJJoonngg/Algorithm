/*
https://www.acmicpc.net/problem/17143
입력
첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
둘째 줄부터 M개의 줄에 상어의 정보가 주어진다.
상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다.
(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5

100 100 0

4 5 4
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4

2 2 4
1 1 1 1 1
2 2 2 2 2
1 2 1 2 3
2 1 2 1 4
출력
낚시왕이 잡은 상어 크기의 합을 출력한다.
22
0
22
4
*/
#include <bits/stdc++.h>
#define MAXI 10000 + 1
struct info { int r, c, s, d, z; };
int R, C, M, res = 0;
int dx[] = { 0,0,0,1,-1 };
int dy[] = { 0,-1,1,0,0 };
int MAP[101][101];
info shark[MAXI];
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
		MAP[shark[i].r][shark[i].c] = i;
	}
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (MAP[j][i] != 0) {
				res += shark[MAP[j][i]].z;
				shark[MAP[j][i]].z = 0;
				MAP[j][i] = 0;
				break;
			}
		}
		for (int j = 1; j <= M; j++) {
			if (!shark[j].z) continue;
			info cur = shark[j];
			MAP[cur.r][cur.c] = 0;
			int dis = cur.s;
			if (cur.d == 1 || cur.d == 2) {
				dis %= (R * 2 - 2);
				while (dis) {
					if (cur.r == 1) cur.d = 2;
					if (cur.r == R) cur.d = 1;
					cur.r += dy[cur.d];
					dis--;
				}
				shark[j].r = cur.r;
				shark[j].d = cur.d;
			}
			else if (cur.d == 3 || cur.d == 4) {
				dis %= (C * 2 - 2);
				while (dis) {
					if (cur.c == 1) cur.d = 3;
					if (cur.c == C) cur.d = 4;
					cur.c += dx[cur.d];
					dis--;
				}
				shark[j].c = cur.c;
				shark[j].d = cur.d;
			}
		}
		for (int j = 1; j <= M; j++) {
			if (!shark[j].z) continue;
			info cur = shark[j];
			if (shark[MAP[cur.r][cur.c]].z < cur.z) {
				shark[MAP[cur.r][cur.c]].z = 0;
				MAP[cur.r][cur.c] = j;
			}
			if (shark[MAP[cur.r][cur.c]].z > cur.z) {
				shark[j].z = 0;
			}
		}
	}
	cout << res << "\n";
}