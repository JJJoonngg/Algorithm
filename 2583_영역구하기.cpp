/*
문제
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 
이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 
그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다.
모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
3
1 7 13
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
int M, N, K, visit[MAX][MAX] = { 0, }, arr[MAX][MAX] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct compare { bool operator()(int& l, int &r) { return l > r; } };
priority_queue<int, vector<int>, compare> res;

int checkRange(int x, int y) { return (0 <= x && x < N && 0 <= y && y < M); }
int dfs(int x, int y) {
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (checkRange(nextX, nextY) && !arr[nextY][nextX] && !visit[nextY][nextX]) {
			visit[nextY][nextX]++;
			cnt += dfs(nextX, nextY);
		}
	}
	return cnt;
}
int main() {
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				arr[y][x]++;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!arr[i][j] && !visit[i][j]) {
				visit[i][j]++;
				res.push(dfs(j, i));
			}
		}
	}

	printf("%d\n", res.size());

	while (!res.empty()) {
		printf("%d ", res.top());
		res.pop();
	}
	printf("\n");
	return 0;
}