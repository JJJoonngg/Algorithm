/*
����
ü���� ���� �� ����Ʈ�� ������ �ִ�. ����Ʈ�� �� ���� �̵��� �� �ִ� ĭ�� �Ʒ� �׸��� �����ִ�.
����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.
����Ʈ�� �� �� �����̸� �� ĭ���� �̵��� �� ������?

�Է�
�Է��� ù° �ٿ��� �׽�Ʈ ���̽��� ������ �־�����.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù° �ٿ��� ü������ �� ���� ���� l(4 �� l �� 300)�� �־�����.
ü������ ũ��� l �� l�̴�. ü������ �� ĭ�� �� ���� �� {0, ..., l-1} �� {0, ..., l-1}�� ��Ÿ�� �� �ִ�.
��° �ٰ� ��° �ٿ��� ����Ʈ�� ���� �ִ� ĭ, ����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.
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
���
�� �׽�Ʈ ���̽����� ����Ʈ�� �� ������ �̵��� �� �ִ��� ����Ѵ�.
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