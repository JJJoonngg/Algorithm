/*
문제
세준이는 2차원 평면에 N개의 점을 찍었다. 그리고 나서 정사각형의 개수를 세려고 한다.
정사각형의 개수란, 세준이가 찍은 서로 다른 N개의 점을 꼭지점으로 하며, 모든 변은 축에 평행한 서로 다른 정사각형을 모두 센 것이다.
세준이는 정사각형의 개수를 최대로 하려고 한다.
N이 주어졌을 때, 정사각형의 개수의 최대값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 이 값은 0보다 크거나 같고, 1000000보다 작거나 같은 값이다.
16

출력
첫째 줄에 정사각형의 개수의 최대값을 출력한다.
14

그리디 알고리즘
수학
기하 알고리즘
*/
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int n, max = 0;
	int w = 0, h = 0, r = 0;
	scanf("%d", &n);
	if (n <= 3) {
		printf("0\n");
		return 0;
	}
	else if (n >= 4) {
		for (int i = 1; i <= n; i++) {
			if (n == pow(i + 1, 2)) {
				max = i * (i + 1)*(2 * i + 1) / 6;
				break;
			}
			if (pow(i + 1, 2) < n && n < pow(i + 2, 2)) {
				h = i;
				w = n / (i + 1) - 1;
				int a = (n - (h + 1)*(w + 1) - 1);
				r = a * (a + 1) / 2;
				if (r > 0) { max = h * (h + 1)*(2 * h + 1) / 6 + (w - h)*h*(h + 1) / 2 + r; }
				else { max = h * (h + 1)*(2 * h + 1) / 6 + (w - h)*h*(h + 1) / 2; }
				break;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}