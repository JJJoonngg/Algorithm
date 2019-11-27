/*
https://www.acmicpc.net/problem/17143
�Է�
ù° �ٿ� �������� ũ�� R, C�� ����� �� M�� �־�����. (2 �� R, C �� 100, 0 �� M �� R��C)
��° �ٺ��� M���� �ٿ� ����� ������ �־�����.
����� ������ �ټ� ���� r, c, s, d, z (1 �� r �� R, 1 �� c �� C, 0 �� s �� 1000, 1 �� d �� 4, 1 �� z �� 10000) �� �̷���� �ִ�.
(r, c)�� ����� ��ġ, s�� �ӷ�, d�� �̵� ����, z�� ũ���̴�. d�� 1�� ���� ��, 2�� ���� �Ʒ�, 3�� ���� ������, 4�� ���� ������ �ǹ��Ѵ�.
�� �� ���� ũ�⸦ ���� ���� ����, �ϳ��� ĭ�� �� �̻��� �� �ִ� ���� ����.
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
���
���ÿ��� ���� ��� ũ���� ���� ����Ѵ�.
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