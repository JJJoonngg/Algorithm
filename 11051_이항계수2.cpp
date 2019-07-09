/*
https://www.acmicpc.net/problem/11051
문제
자연수 n과 정수 k가 주어졌을 때 이항 계수(n,k) 를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 과 가 주어진다. (1 ≤ n ≤ 1,000, 0 ≤ k ≤ n)
5 2
출력
(n,k)를 10,007로 나눈 나머지를 출력한다.
10

알고리즘 분류 : 다이나믹 프로그래밍
해결책 : 파스칼의 삼각형
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