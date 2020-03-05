/*
https://www.acmicpc.net/problem/7569
�Է�
ù �ٿ��� ������ ũ�⸦ ��Ÿ���� �� ���� M,N�� �׾ƿ÷����� ������ ���� ��Ÿ���� H�� �־�����.
M�� ������ ���� ĭ�� ��, N�� ������ ���� ĭ�� ���� ��Ÿ����. ��, 2 �� M �� 100, 2 �� N �� 100, 1 �� H �� 100 �̴�.
��° �ٺ��ʹ� ���� ���� ���ں��� ���� ���� ���ڱ����� ����� �丶����� ������ �־�����.
��, ��° �ٺ��� N���� �ٿ��� �ϳ��� ���ڿ� ��� �丶���� ������ �־�����.
�� �ٿ��� ���� �����ٿ� ����ִ� �丶����� ���°� M���� ������ �־�����.
���� 1�� ���� �丶��, ���� 0 �� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����. �̷��� N���� ���� H�� �ݺ��Ͽ� �־�����.
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
���
�������� �丶�䰡 ��� ���� ������ �ּ� ��ĥ�� �ɸ������� ����ؼ� ����ؾ� �Ѵ�.
����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.
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