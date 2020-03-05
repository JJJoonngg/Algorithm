/*
https://www.acmicpc.net/problem/1743
����
�ڷ����� �ܵ��̴Ͼ� 8���� �л����� 3���� �Ļ縦 �ذ��ϴ� �����̴�. �׷��� ��� �������� �л����� �������� ���Ĺ��� ��� �߰� �߰��� ������ �ִ�. 
�̷��� ���Ĺ����� ��ó�� �ִ� �ͳ��� ��ġ�� �ż� ū ���Ĺ� �����Ⱑ �ȴ�.
�� ������ ������ �������� ���������� �̷��� ���Ĺ��� �ǳ�ȭ�� ������ ���� ���� �������� �Ⱦ��Ѵ�. ����� �츮�� ���ؾ� �� ���� �� ������ �� ������ ���ߴ� ���� �ƴϴ�.
��ο� ������ ���Ĺ��� ���ذ���� ���� ���� �ƴϴ�. ���� �������� ������ ���Ĺ� �߿� ���� ū ���Ĺ����� ���� ������ �Ѵ�.

�������� ���� ���� ū ���Ĺ��� ũ�⸦ ���ؼ� ��10ra"�� ��ġ�� �ʰ� ��������.

�Է�
ù° �ٿ� ����� ���� ���� N(1 �� N �� 100)�� ���� ���� M(1 �� M �� 100) �׸��� ���Ĺ� �������� ���� K(1 �� K �� 10,000)�� �־�����. 
�׸��� ���� K���� �ٿ� ���Ĺ��� ������ ��ǥ (r, c)�� �־�����.

��ǥ (r, c)�� r�� ����������, c�� ���ʿ������Ͱ� �����̴�.
3 4 5
3 2
2 2
3 1
2 3
1 1

���
ù° �ٿ� ���Ĺ��� ���� ū ���Ĺ��� ũ�⸦ ����϶�.
4
*/
#include <iostream>
#include <algorithm>
#define MAXI 100 + 1
using namespace std;
int n, m, k, ans = 0, cnt = 0;
int arr[MAXI][MAXI] = { 0, };
bool visit[MAXI][MAXI] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool checkRange(int x, int y) { return x > 0 && x <= n && y > 0 && y <= m; }
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (checkRange(nextX, nextY) && !visit[nextX][nextY] && arr[nextX][nextY]) {
			cnt++; dfs(nextX, nextY);
		}
	}
}
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && arr[i][j]) {
				cnt = 1; dfs(i, j);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << "\n";
}