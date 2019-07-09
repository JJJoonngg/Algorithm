/*
https://www.acmicpc.net/problem/6593
문제
당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.

당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?

입력
입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다. L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.

그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 각 문자는 상범 빌딩의 한 칸을 나타낸다. 금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다. 당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 출구는 'E'로 표현된다. 각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다.
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
출력
각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.

Escaped in x minute(s).
여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.

만일 탈출이 불가능하다면, 다음과 같이 출력한다.

Trapped!

Escaped in 11 minute(s).
Trapped!

알고리즘 분류 : DFS, BFS, 다익스트라
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAXI 30 + 1
using namespace std;
struct info { int x; int y; int z; };
info Star, _end;
int L, R, C;
bool checkRange(info tmp) { return 0 <= tmp.x && tmp.x < L && 0 <= tmp.y && tmp.y < R && 0 <= tmp.z && tmp.z < C; }
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,-1,1,0,0 };
char arr[MAXI][MAXI][MAXI];
int check[MAXI][MAXI][MAXI];
int bfs(info input, info output) {
	queue<info> q;
	q.push(input);
	while (!q.empty()) {
		info cur = q.front(); q.pop();
		if (cur.x == output.x && cur.y == output.y && cur.z == output.z) return check[cur.x][cur.y][cur.z];
		for (int i = 0; i < 6; i++) {
			info next;
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			next.z = cur.z + dz[i];
			if (arr[next.x][next.y][next.z] == '#') continue;
			if (!check[next.x][next.y][next.z] && checkRange(next)) {
				check[next.x][next.y][next.z] = check[cur.x][cur.y][cur.z] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		memset(arr, ' ', sizeof(arr));
		memset(check, 0, sizeof(check));
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') Star.x = i, Star.y = j, Star.z = k;
					if (arr[i][j][k] == 'E') _end.x = i, _end.y = j, _end.z = k;
				}
			}
		}
		int res = bfs(Star, _end);
		if (res == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << res << " minute(s).\n";
	}
}