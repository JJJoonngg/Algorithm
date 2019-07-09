/*
문제
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

입력
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 
그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다.
N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3
출력
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.
-1 -2 6
-3 -6 12
-5 -10 18
*/
#include <iostream>
#define	MAX 101
using namespace std;
int arr1[MAX][MAX], arr2[MAX][MAX], arr3[MAX][MAX], n, m, k;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr1[i][j]);

	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++) 
			scanf("%d", &arr2[i][j]);

	for (int a = 0; a < n; a++) 
		for (int b = 0; b < k; b++)
			for (int c = 0; c < m; c++) 
				arr3[a][b] += arr1[a][c] * arr2[c][b];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			printf("%d ", arr3[i][j]);
		printf("\n");
	}
	return 0;
}