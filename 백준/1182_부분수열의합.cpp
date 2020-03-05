/*
https://www.acmicpc.net/problem/1182
문제
N개의 정수로 이루어진 수열이 있을 때, 길이가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000)
둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
5 0
-7 -3 -2 5 8
출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
1
*/
#include <iostream>
int  arr[21], n, s, ans = 0;
void dfs(int index, int sum) {
	if (index >= n) return;

	if (sum + arr[index] == s) ans++;

	dfs(index+1, sum + arr[index]);
	dfs(index + 1, sum);
}
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	dfs(0, 0);
	printf("%d\n", ans);
}