/*
����
���� Rĭ, ���� Cĭ���� �� ǥ ����� ���尡 �ִ�. ������ �� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ְ�, ���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.
���� �����¿�� ������ �� ĭ ���� �� ĭ���� �̵��� �� �ִµ�, ���� �̵��� ĭ�� ���� �ִ� ���ĺ��� ���ݱ��� ������ ��� ĭ�� ���� �ִ� ���ĺ����� �޶�� �Ѵ�. 
��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.
���� ��ܿ��� �����ؼ�, ���� �ִ��� �� ĭ�� ���� �� �ִ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.

�Է�
ù° �ٿ� R�� C�� ��ĭ�� ���̿� �ΰ� �־�����. (1<=R,C<=20) ��° �ٺ��� R���� �ٿ� ���ļ� ���忡 ���� �ִ� C���� �빮�� ���ĺ����� ��ĭ ���� �־�����.
2 4
CAAB
ADCB

���
ù° �ٿ� ���� ���� �� �ִ� �ִ��� ĭ ���� ����Ѵ�.
3
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char board[MAX][MAX];
int R, C, res = 0;
bool check[MAX];
int checkRange(int x, int y) { return (0 <= x && x < C && 0 <= y && y < R); }
void dfs(int x, int y,int cnt) {
	res = max(res, cnt);
	check[board[y][x] - 65] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (checkRange(nextX, nextY) && !check[board[nextY][nextX] - 65])
			dfs(nextX, nextY,cnt+1);
	}
	check[board[y][x] - 65] = false;
}
int main() {
	scanf("%d %d", &R, &C);
	
	for (int i = 0; i < R; i++)
		scanf("%s", &board[i]);

	check[board[0][0] - 65] = true;
	dfs(0, 0, 1);

	printf("%d\n", res);
	return 0;
}