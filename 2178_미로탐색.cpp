/*
문제
N×M크기의 배열로 표현되는 미로가 있다.
1 0 1 1 1 1
1 0 1 0 1 0
1 0 1 0 1 1
1 1 1 0 1 1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2≤N, M≤100)이 주어진다.
다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
4 6
101111
101010
101011
111011

4 6
110110
110110
111111
111101

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
15
9
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX 101
char graph[MAX][MAX];
int check[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct xy
{
	int x;
	int y;
};
queue<xy> q;
void bfs() {
	q.push({ 1,1 });
	check[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (graph[x + dx[i]][y + dy[i]] == '1' && check[x + dx[i]][y + dy[i]] == 1) {
				q.push({ x + dx[i],y + dy[i] });
				check[x + dx[i]][y + dy[i]] = check[x][y] + 1;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check[i][j] = -1;
			cin >> graph[i][j];
			if (graph[i][j] == '1') check[i][j] = 1;
		}
	}
	bfs();
	cout << check[N][M] << endl;
	return 0;
}