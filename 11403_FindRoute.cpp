/*
문제
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, 
i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 
둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다. 
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. 
i번째 줄의 i번째 숫자는 항상 0이다.
3
0 1 0
0 0 1
1 0 0

7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다. 
정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
1 1 1
1 1 1
1 1 1

1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0
*/
#include <iostream>
#define MAX 101
using namespace std;
int N;
int matrix[MAX][MAX];
int result[MAX][MAX];

void FindRoute(int a,int b) {
	//경로를 dfs로 찾으며, 이미 지나간 경로는 다시 탐색하지 않기위해 if 문에 result != 1 조건을 걸었다.
	//해당 경로가 존재하면 결과값을 1 이라고 저장하고 다시 호출하여 dfs를 반복한다.
	for (int i = 1; i <= N; i++) {
		if (matrix[a][i] == 1 && result[b][i] != 1) {
			result[b][i] = 1;
			FindRoute(i, b);
		}
	}
}
int main() {
	//입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
		}
	}
	//입력받은 정점의 갯수만큼 dfs를 실행한다.
	for (int i = 1; i <= N; i++) {
		FindRoute(i, i);
	}
	//출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}