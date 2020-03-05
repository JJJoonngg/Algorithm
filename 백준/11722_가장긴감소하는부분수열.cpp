/*
����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 30, 10, 20, 20, 10}  �̰�, ���̴� 3�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)
6
10 30 10 20 20 10
���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
3
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
		dp[i]++;
		for (int j = 1; j < i; j++)
			if (arr[i] < arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		res = max(dp[i], res);
	}
	printf("%d\n", res);
	return 0;
}