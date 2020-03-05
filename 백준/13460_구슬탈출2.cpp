/*
https://www.acmicpc.net/problem/13460
�Է�
ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M (3 �� N, M �� 10)�� �־�����. ���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����. �� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�. '.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�. 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.

�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�. ������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.
5 5
#####
#..B#
#.#.#
#RO.#
#####

7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######
���
�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�. ����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ����Ѵ�.
1
5
*/
#include <bits/stdc++.h>
#define MAXI 10
using namespace std;
struct info { int x, y; };
struct ball { int cnt; info red; info blue; };
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int n, m;
char MAP[MAXI][MAXI];
bool visit[MAXI][MAXI][MAXI][MAXI];
bool checkRange(int x, int y) { return 0 < y&&y < n - 1 && 0 < x&&x < m - 1; }
info _goal, _red, _blue;
void move(info &tmp, int dir, int &cnt) {
	while (true) {
		tmp.x += dx[dir];
		tmp.y += dy[dir];
		char now = MAP[tmp.x][tmp.y];
		if (now == 'O') break;
		else if (now == '#') {
			tmp.x -= dx[dir];
			tmp.y -= dy[dir];
			break;
		}
		cnt++;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'O') _goal.x = i, _goal.y = j;
			if (MAP[i][j] == 'R') _red.x = i, _red.y = j;
			if (MAP[i][j] == 'B') _blue.x = i, _blue.y = j;
		}
	}
	int res = -1;
	queue<ball> q;
	q.push({ 0,_red,_blue });
	visit[_red.x][_red.y][_blue.x][_blue.y] = true;
	while (!q.empty()) {
		ball now = q.front(); q.pop();
		if (now.cnt > 10) break;
		if (MAP[now.red.x][now.red.y] == 'O') {
			res = now.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int redCnt = 0;
			int blueCnt = 0;
			_red = now.red;
			_blue = now.blue;
			move(_red, i, redCnt);
			move(_blue, i, blueCnt);
			if (MAP[_blue.x][_blue.y] == 'O') continue;
			if (_blue.x == _red.x && _blue.y == _red.y) {
				if (redCnt > blueCnt) _red.x -= dx[i], _red.y -= dy[i];
				else _blue.x -= dx[i], _blue.y -= dy[i];
			}
			if (visit[_red.x][_red.y][_blue.x][_blue.y]) continue;
			visit[_red.x][_red.y][_blue.x][_blue.y] = true;
			q.push({ now.cnt + 1, _red, _blue });
		}
	}
	cout << res << "\n";
}
