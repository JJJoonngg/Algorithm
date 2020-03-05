/*
https://www.acmicpc.net/problem/1978
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
4
1 3 5 7
출력
주어진 수들 중 소수의 개수를 출력한다.
3
*/
#include <iostream>
#include <cmath>
int main() {
	int n, cnt = 0, arr[101] = { 0, }, mod[1001] = { 0, };
	scanf("%d", &n);
	for (int i = 2; i <= sqrt(1000); i++) {
		if (mod[i]) continue;
		for (int j = i + i; j <= 1000; j += i)
			mod[j] = true;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1) continue;
		if (!mod[arr[i]]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}