/*
https://www.acmicpc.net/problem/6593
����
����� ��� ������ ������ ���Ҵ�. ���⼭ Ż���ϴ� ���� ���� ���� �����ϱ�? ��� ������ �� ���� ���̰� 1�� ������ü(���� ������ü)�� �̷�����ִ�. �� ������ü�� ������ �̷���� �־� ������ �� ���ų�, ����־ ������ �� �ְ� �Ǿ��ִ�. ����� �� ĭ���� ������ 6���� ĭ(��,��,��,��,��,��)���� 1���� �ð��� �鿩 �̵��� �� �ִ�. ��, �밢������ �̵��ϴ� ���� �Ұ����ϴ�. �׸��� ��� ������ �ٱ��鵵 ��� ������ �����־� �ⱸ�� ���ؼ��� Ż���� �� �ִ�.

����� ��� ������ Ż���� �� ������? ���� �׷��ٸ� �󸶳� �ɸ���?

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷������, �� �׽�Ʈ ���̽��� �� ���� ���� L, R, C�� �����Ѵ�. L(1 �� L �� 30)�� ��� ������ �� ���̴�. R(1 �� R �� 30)�� C(1 �� C �� 30)�� ��� ������ �� ���� ��� ���� ������ ��Ÿ����.

�� ���� �� ���� C���� ���ڷ� �̷���� R���� ���� L�� �־�����. �� ���ڴ� ��� ������ �� ĭ�� ��Ÿ����. ������ �����־� ������ �� ���� ĭ�� '#'���� ǥ���ǰ�, ����ִ� ĭ�� '.'���� ǥ���ȴ�. ����� ���� ������ 'S'�� ǥ���ǰ�, Ż���� �� �ִ� �ⱸ�� 'E'�� ǥ���ȴ�. �� �� ���̿��� �� ���� ������, �Է��� ���� L, R, C�� ��� 0���� ǥ���ȴ�.
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
���
�� ������ ���� �� �پ� ���� ����Ѵ�. ���� ����� Ż���� �� �ִٸ� ������ ���� ����Ѵ�.

Escaped in x minute(s).
���⼭ x�� ��� ������ Ż���ϴ� ���� �ʿ��� �ִ� �ð��̴�.

���� Ż���� �Ұ����ϴٸ�, ������ ���� ����Ѵ�.

Trapped!

Escaped in 11 minute(s).
Trapped!

�˰��� �з� : DFS, BFS, ���ͽ�Ʈ��
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAXI 30 + 1
using namespace std;
struct info { int x; int y; int z; };
info Star, _end;
int L, R, C;
bool checkRange(info tmp) { return 0 <= tmp.x && tmp.x < L && 0 <= tmp.y && tmp.y < R && 0 <= tmp.z && tmp.z < C; }
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,-1,1,0,0 };
char arr[MAXI][MAXI][MAXI];
int check[MAXI][MAXI][MAXI];
int bfs(info input, info output) {
	queue<info> q;
	q.push(input);
	while (!q.empty()) {
		info cur = q.front(); q.pop();
		if (cur.x == output.x && cur.y == output.y && cur.z == output.z) return check[cur.x][cur.y][cur.z];
		for (int i = 0; i < 6; i++) {
			info next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			next.z = cur.z + dz[i];
			if (arr[next.x][next.y][next.z] == '#') continue;
			if (!check[next.x][next.y][next.z] && checkRange(next)) {
				check[next.x][next.y][next.z] = check[cur.x][cur.y][cur.z] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		memset(arr, ' ', sizeof(arr));
		memset(check, 0, sizeof(check));
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') Star.x = i, Star.y = j, Star.z = k;
					if (arr[i][j][k] == 'E') _end.x = i, _end.y = j, _end.z = k;
				}
			}
		}
		int res = bfs(Star, _end);
		if (res == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << res << " minute(s).\n";
	}
}