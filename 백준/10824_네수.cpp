/*
https://www.acmicpc.net/problem/10824
문제
네 자연수 A, B, C, D가 주어진다. 이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오.
두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다. 즉, 20과 30을 붙이면 2030이 된다.

입력
첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)
10 20 30 40
출력
A와 B를 붙인 수와 C와 D를 붙인 수의 합을 출력한다.
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