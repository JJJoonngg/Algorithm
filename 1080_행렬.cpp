/*
https://www.acmicpc.net/problem/1080
문제
0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.
행렬을 변환하는 연산은 어떤 3*3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 -> 1, 1 -> 0)

입력
첫째 줄에 행렬의 크기 N M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개의 줄에는 행렬 A가 주어지고, 그 다음줄부터 N개의 줄에는 행렬 B가 주어진다.
3 4
0000
0010
0000
1001
1011
1001
출력
첫째 줄에 문제의 정답을 출력한다. 만약 A를 B로 바꿀 수 없다면 -1을 출력한다.
2
*/
#include <iostream>
#define MAXI 51
using namespace std;
int first[MAXI][MAXI];
int second[MAXI][MAXI] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &first[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			scanf("%1d", &second[i][j]);
		}
	}
	int res = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (first[i][j] != second[i][j]) {
				res++;
				for (int a = i; a <= i + 2; a++) {
					for (int b = j; b <= j + 2; b++) {
						first[a][b] = 1 - first[a][b];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (first[i][j] != second[i][j])
				res = -1;
		}
	}
	printf("%d\n", res);
}