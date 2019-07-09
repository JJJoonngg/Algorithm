/*
https://www.acmicpc.net/problem/10824
����
�� �ڿ��� A, B, C, D�� �־�����. �̶�, A�� B�� ���� ���� C�� D�� ���� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� �� A�� B�� ��ġ�� ���� A�� �ڿ� B�� ���̴� ���� �ǹ��Ѵ�. ��, 20�� 30�� ���̸� 2030�� �ȴ�.

�Է�
ù° �ٿ� �� �ڿ��� A, B, C, D�� �־�����. (1 �� A, B, C, D �� 1,000,000)
10 20 30 40
���
A�� B�� ���� ���� C�� D�� ���� ���� ���� ����Ѵ�.
4060
*/
#include <iostream>
int main() {
	long long a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	long long tmpB = b, tmpD = d;
	long long n = 1, m = 1;
	while (tmpB > 0) { tmpB /= 10;	n *= 10; }
	while (tmpD > 0) { tmpD /= 10;	m *= 10; }
	printf("%lld\n", (n*a + b) + (m*c) + d);
}