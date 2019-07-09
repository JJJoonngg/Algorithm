/*
https://www.acmicpc.net/problem/4963
����
���簢������ �̷���� �ִ� ���� �ٴ� ������ �־�����. ���� ������ ���� ���α׷��� �ۼ��Ͻÿ�.
�� ���簢���� ����, ���� �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� �ɾ �� �ִ� �簢���̴�.
�� ���簢���� ���� ���� ��������, �� ���簢������ �ٸ� ���簢������ �ɾ �� �� �ִ� ��ΰ� �־�� �Ѵ�.
������ �ٴٷ� �ѷ��׿� ������, ���� ������ ���� �� ����.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �ʺ� w�� ���� h�� �־�����.
w�� h�� 50���� �۰ų� ���� ���� �����̴�.
��° �ٺ��� h�� �ٿ��� ������ �־�����. 1�� ��, 0�� �ٴ��̴�.
�Է��� ������ �ٿ��� 0�� �� �� �־�����.
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
���
�� �׽�Ʈ ���̽��� ���ؼ�, ���� ������ ����Ѵ�.
0
1
1
3
1
9
*/
#include <iostream>
#include <string.h>
using namespace std;
int dx[] = { 0,0,1,-1,-1,1,1,-1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
struct xy { int x; int y; };
int visit[51][51] = { 0, };
int map[51][51] = { 0, };
int w, h;
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < h&&nextY >= 0 && nextY < w && !visit[nextX][nextY] && map[nextX][nextY] == 1) {
			dfs(nextX, nextY);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));

		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) 
				cin >> map[i][j];
		int res = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && map[i][j]) {
					dfs(i, j);
					res++;
				}
			}
		}
		cout << res << "\n";
	}
}