/*
https://www.acmicpc.net/problem/2292
�Է�
ù° �ٿ� N(1 �� N �� 1,000,000,000)�� �־�����.
13
58
���
�Է����� �־��� ����� �ּ� ������ ���� ������ �� �� �� ���� ���� �������� ����Ѵ�.
3
5
*/
#include <iostream>
#include <cstdio>
int main() {
	int n, res = 1;
	scanf("%d", &n);
	if (n == 1) res = 1;
	else if (2<=n&&n<=7) res = 2;
	else for(int i=3;;i++)	if (n < 3 * i*i - 9 * i + 8) {	res = i - 1; break;	}
	printf("%d\n", res);
}