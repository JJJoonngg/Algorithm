/*
https://www.acmicpc.net/problem/2292
입력
첫째 줄에 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.
13
58
출력
입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나는지 출력한다.
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