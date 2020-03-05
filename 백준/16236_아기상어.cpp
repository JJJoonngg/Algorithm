/*
https://www.acmicpc.net/problem/16236
����
N��N ũ���� ������ ����� M������ �Ʊ� ��� 1������ �ִ�. ������ 1��1 ũ���� ���簢�� ĭ���� �������� �ִ�. �� ĭ���� ����Ⱑ �ִ� 1���� �����Ѵ�.

�Ʊ� ���� ������ ��� ũ�⸦ ������ �ְ�, �� ũ��� �ڿ����̴�. ���� ó���� �Ʊ� ����� ũ��� 2�̰�, �Ʊ� ���� 1�ʿ� �����¿�� ������ �� ĭ�� �̵��Ѵ�.

�Ʊ� ���� �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����, ������ ĭ�� ��� ������ �� �ִ�.
�Ʊ� ���� �ڽ��� ũ�⺸�� ���� ����⸸ ���� �� �ִ�. ����, ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.

�Ʊ� �� ���� �̵����� �����ϴ� ����� �Ʒ��� ����.

�� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּڰ��̴�.
�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.
�Ʊ� ����� �̵��� 1�� �ɸ���, ����⸦ �Դµ� �ɸ��� �ð��� ���ٰ� �����Ѵ�.
��, �Ʊ� �� ���� �� �ִ� ����Ⱑ �ִ� ĭ���� �̵��ߴٸ�, �̵��� ���ÿ� ����⸦ �Դ´�. ����⸦ ������, �� ĭ�� �� ĭ�� �ȴ�.

�Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 �����Ѵ�. ���� ���, ũ�Ⱑ 2�� �Ʊ� ���� ����⸦ 2���� ������ ũ�Ⱑ 3�� �ȴ�.

������ ���°� �־����� ��, �Ʊ� �� �� �� ���� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N(2 �� N �� 20)�� �־�����.

��° �ٺ��� N���� �ٿ� ������ ���°� �־�����. ������ ���´� 0, 1, 2, 3, 4, 5, 6, 9�� �̷���� �ְ�, �Ʒ��� ���� �ǹ̸� ������.

 - 0: �� ĭ
 - 1, 2, 3, 4, 5, 6: ĭ�� �ִ� ������� ũ��
 - 9: �Ʊ� ����� ��ġ
�Ʊ� ���� ������ �� ���� �ִ�.

���
ù° �ٿ� �Ʊ� �� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ� �ð��� ����Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define MAXI 20 + 1
using namespace std;
int N;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
struct info { int x; int y; int dis; };
struct shark { int x; int y; int siz; int dis; int time; int eat; };
int map[MAXI][MAXI];
bool visit[MAXI][MAXI];
shark S;
bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }
bool comp(info tmp1, info tmp2) {
	if (tmp1.dis != tmp2.dis) return tmp1.dis < tmp2.dis;
	else {
		if (tmp1.x == tmp2.x) return tmp1.y < tmp2.y;
		else return tmp1.x < tmp2.x;
	}
}
vector<info> v;
void bfs(int x, int y) {
	queue<info> q;
	q.push({ x,y,0 });
	visit[x][y] = true;
	while (!q.empty()) {
		info cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = cur.x + dx[i];
			int nextY = cur.y + dy[i];
			if (checkRange(nextX, nextY) && !visit[nextX][nextY]) {
				if (!map[nextX][nextY] || map[nextX][nextY] == S.siz) {
					visit[nextX][nextY] = true;
					q.push({ nextX,nextY,cur.dis + 1 });
				}
				else if (map[nextX][nextY] < S.siz) {
					info tmp;
					tmp.x = nextX, tmp.y = nextY, tmp.dis = cur.dis + 1;
					v.push_back(tmp);
					visit[nextX][nextY] = true;
					q.push({ nextX,nextY,cur.dis + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)	S.x = i, S.y = j, S.siz = 2, S.eat = 0, S.time = 0, map[i][j] = 0;
		}
	}
	while (true) {
		v.clear();
		memset(visit, false, sizeof(visit));
		bfs(S.x, S.y);
		if (!v.size()) {
			cout << S.time << "\n";
			break;
		}
		else if (v.size() == 1) {
			map[S.x][S.y] = 0;
			map[v[0].x][v[0].y] = 9;
			S.x = v[0].x, S.y = v[0].y;
			S.eat++;
			S.time += v[0].dis;
			if (S.eat == S.siz) S.eat = 0, S.siz++;
		}
		else {
			sort(v.begin(), v.end(), comp);
			map[S.x][S.y] = 0;
			map[v[0].x][v[0].y] = 9;
			S.x = v[0].x, S.y = v[0].y;
			S.eat++;
			S.time += v[0].dis;
			if (S.eat == S.siz) S.eat = 0, S.siz++;
		}
	}
}