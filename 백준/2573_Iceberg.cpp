/*
입력
첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다.
N과 M은 3 이상 300 이하이다. 
그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다.
각 칸에 들어가는 값은 0 이상 10 이하이다. 
배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다.
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
출력
첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
2
*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define MAX 301
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[MAX][MAX];
int melt[MAX][MAX];
int visit[MAX][MAX];
int N, M, res;
int checkRange(int x, int y) {return (0 <= x && x < M && 0 <= y && y < N);}
void dfs(int x, int y) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		if (!visit[nextY][nextX] && map[nextY][nextX] > 0 && checkRange(nextX, nextY)) {
			dfs(nextX, nextY);
		}
	}
}

int cntIceberg() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && map[i][j] > 0) {
				cnt++;
				dfs(j, i);
			}
		}
	}
	return cnt;
}
int nextYear(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		if (map[nextY][nextX] <= 0 && map[y][x] > 0 && checkRange(nextX, nextY))
			cnt++;
	}
	return cnt++;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	int tmp = 0;
	while ((tmp = cntIceberg()) < 2) {
		memset(visit, 0, sizeof(visit));
		if (tmp == 0) {
			res = 0;
			break;
		}	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0) melt[i][j] = nextYear(j, i);
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] -= melt[i][j];
		res++;
	}
	printf("%d\n", res);

	return 0;
}