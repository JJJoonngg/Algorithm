/*
https://www.acmicpc.net/problem/1018
����
�����̴� �ڽ��� ���ÿ��� MN���� ���� ���簢������ �������� �ִ� M*Nũ���� ���带 ã�Ҵ�. � ���簢���� ���������� ĥ�����ְ�, �������� ������� ĥ���� �ִ�. 
�����̴��� ���带 �߶� 8*8ũ���� ü�������� ������� �Ѵ�.

������ �����̴� �� ���尡 ü����ó�� ����/��� ������ �����ư��� ��ĥ�������� �ʱ� ������ ��ο� ������. 
���� �����̴� 8*8ũ���� ü�������� �߶� �Ŀ� �� ���� ���簢���� �ٽ� ĥ�ؾ� �ڴٰ� �����ߴ�. �翬�� 8*8ũ��� �ƹ������� ��� �ȴ�.

���� ������ ���� ��� ���°� �־��� ��, �����̰� 8*8ũ��� �ڸ� �ڿ� �ٽ� ĥ�ؾ��ϴ� ���簢�� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ü������ �� ���簢���� ���� �Ǵ� ����̸�, ���� �����ϴ� �� ���� �簢���� ���� ���� �ƴ� �� �̴�. 
���� �� ���ǿ� ���ϸ� ü������ ���� �׻� �� ������ �����ѵ�, �ϳ��� ���� �� �ڳʰ� ����� ��, �������� �� �ΰ����̴�.

�Է�
ù° �ٿ� N�� M�� �־�����. M�� N�� 8���� ũ�ų� ����, 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N�� �ٿ��� ü������ �� ���°� �־�����. B�� �������̸�, W�� ����̴�.
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW

10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB
���
ù° �ٿ� �����̰� 8*8ũ��� �ڸ� �ڿ� �ٽ� ĥ�ؾ��ϴ� ���簢�� ������ �ּڰ��� ����Ѵ�.
1
12

�˰��� �з�
���Ʈ ����
�ùķ��̼�
*/
#include <bits/stdc++.h>
#define INF 1e9
#define MAXI 50 + 1
using namespace std;
int n, m, cnt,res;
string map[MAXI];
vector<char> whiteMap[8], blackMap[8];
void init() {
	res = INF;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2) {
				if (j % 2) {
					whiteMap[i].push_back('W');
					blackMap[i].push_back('B');
				}
				else {
					whiteMap[i].push_back('B');
					blackMap[i].push_back('W');
				}
			}
			else {
				if (j % 2) {
					whiteMap[i].push_back('B');
					blackMap[i].push_back('W');
				}
				else {
					whiteMap[i].push_back('W');
					blackMap[i].push_back('B');
				}
			}
		}
	}
}
int white(int y, int x) {
	cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (map[i][j] != whiteMap[i - y][j - x])
				cnt++;
	return cnt;
}
int black(int y, int x) {
	cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (map[i][j] != blackMap[i - y][j - x])
				cnt++;
	return cnt;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++)	cin >> map[i];
	for (int i = 0; i < n - 7; i++)
		for (int j = 0; j < m - 7; j++)
			res = min(res, min(white(i, j), black(i, j)));
	cout << res << "\n";
}