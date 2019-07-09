/*
문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 
즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1<=R,C<=20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.
2 4
CAAB
ADCB

출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.
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