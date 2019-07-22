/*
https://www.acmicpc.net/problem/16236
문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다.
즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.

둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.

 - 0: 빈 칸
 - 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
 - 9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

출력
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.
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