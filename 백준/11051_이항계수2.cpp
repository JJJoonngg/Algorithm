/*
https://www.acmicpc.net/problem/11051
����
�ڿ��� n�� ���� k�� �־����� �� ���� ���(n,k) �� 10,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� �� �־�����. (1 �� n �� 1,000, 0 �� k �� n)
5 2
���
(n,k)�� 10,007�� ���� �������� ����Ѵ�.
10

�˰��� �з� : ���̳��� ���α׷���
�ذ�å : �Ľ�Į�� �ﰢ��
*/
#include <iostream>
#define mod 10007
#define MAXI 1001
using namespace std;
int n, k, dp[MAXI][MAXI] = { 0, };
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
		}
	}
	cout << dp[n][k] << "\n";
}