/*
입력
입력의 첫째 줄에 게임에서 승리할 확률 W, 질 확률 L,비길 확률 D가 0 이상의 실수로 주어진다. (W+L+D=1) 입력은 소수점 둘째짜리까지 들어온다.
0.5 0.5 0
출력
브론즈, 실버, 골드, 플래티넘, 다이아에 배정받을 확률을 각 줄에 출력한다. (소수점 아래 9번째 자리에서 반올림하여 소수점 8자리까지 출력)
0.00590897
0.40599251
0.56740379
0.02069378
0.00000095
*/
#include <stdio.h>
double w, l, d;
double arr[21][3001] = { 0, };
int main() {
	scanf("%lf %lf %lf", &w, &l, &d);
	arr[0][2000] = 1;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1000; j <= 3000; j++) {
			if (arr[i - 1][j] == 0) continue;

			arr[i][j + 50] += arr[i - 1][j] * w;
			arr[i][j - 50] += arr[i - 1][j] * l;
			arr[i][j] += arr[i - 1][j] * d;
		}
	}
	double b = 0.0, s = 0.0, g = 0.0, p = 0.0, d = 0.0;
	for (int i = 1000; i <= 3000; i++) {
		if (1000 <= i && i <= 1499) b += arr[20][i];
		else if (1500 <= i && i <= 1999) s += arr[20][i];
		else if (2000 <= i && i <= 2499) g += arr[20][i];
		else if (2500 <= i && i <= 2999) p += arr[20][i];
		else d += arr[20][i];
	}
	printf("%.8lf\n", b);
	printf("%.8lf\n", s);
	printf("%.8lf\n", g);
	printf("%.8lf\n", p);
	printf("%.8lf\n", d);
}