/*
https://www.acmicpc.net/problem/10872
문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.
10
출력
첫째 줄에 N!을 출력한다.
3628800
*/
#include <iostream>
int main() {
	int n, arr[13];
	arr[0] = 1;
	for (int i = 1; i < 13; i++) arr[i] = i * arr[i - 1];
	scanf("%d", &n);
	printf("%d\n", arr[n]);
}