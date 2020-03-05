/*
문제
N행 N열로 이루어진 정사각형 행렬 A가 주어진다. 이때, 쿼리를 수행하는 프로그램을 작성하시오.
x1 y1 x2 y2: 왼쪽 윗칸이 (x1, y1)이고, 오른쪽 아랫칸이 (x2, y2)인 부분 행렬에 포함되어 있는 서로 다른 정수의 개수를 출력한다.

입력
첫째 줄에 N (1 ≤ N ≤ 300)이 주어진다. 다음 N개의 줄에는 행렬의 정보가 주어지며,
각 줄은 N개의 수로 이루어져 있다. 행은 위에서부터 아래로, 열은 왼쪽부터 오른쪽으로 번호가 매겨져 있으며,
번호는 1번부터 시작한다. 행렬이 포함하고 있는 정수는 10보다 작거나 같은 자연수이다.
다음 줄에는 Q (1 ≤ Q ≤ 100,000)가 주어진다. 다음 Q개의 줄에는 쿼리의 정보 x1, y1, x2, y2가 주어진다. (1 ≤ x1 ≤ x2 ≤ n, 1 ≤ y1 ≤ y2 ≤ n)
3
1 2 3
3 2 1
5 6 3
3
1 1 2 3
2 2 2 2
1 1 3 3
출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.
3
1
5
*/
#include <iostream>
#define MAX 301
int n, q, arr[MAX][MAX], tmp[11], arr2[MAX][MAX][11];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 10; k++) {
				arr2[i][j][k] += arr2[i - 1][j][k];
				arr2[i][j][k] += arr2[i][j - 1][k];
				arr2[i][j][k] -= arr2[i - 1][j - 1][k];
			}
			arr2[i][j][arr[i][j]]++;
		}
	}
	scanf("%d", &q);
	while (q--) {
		int x1, y1, x2, y2, res = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = 1; i <= 10; i++) {
			tmp[i] = arr2[x2][y2][i];
			tmp[i] -= arr2[x1 - 1][y2][i];
			tmp[i] -= arr2[x2][y1 - 1][i];
			tmp[i] += arr2[x1 - 1][y1 - 1][i];
			if (tmp[i] > 0)res++;
		}
		printf("%d\n", res);
	}
	return 0;
}