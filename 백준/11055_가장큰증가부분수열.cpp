/*
����
���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ��쿡 ���� ���� ū ���� �κ� ������ A = {'1', 100, '2', '50', '60', 3, 5, 6, 7, 8} �̰�, ���� 113�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)
10
1 100 2 50 60 3 5 6 7 8

���
ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.
113
*/
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int dp[MAX] = { 0, }, arr[MAX] = { 0, }, N, res = 0;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
			if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) dp[i] = dp[j] + arr[i];
		res = max(dp[i], res);
	}
	printf("%d\n", res);
	return 0;
}