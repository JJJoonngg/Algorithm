/*
https://www.acmicpc.net/problem/11050
문제
자연수 n과 정수 k가 주어졌을 때 이항 계수(n,k) 를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 과 가 주어진다. (1 ≤ n ≤ 10, 0 ≤ k ≤ n)
5 2
출력
(n,k)를 출력한다.
10
*/
#include <iostream>
using namespace std;
int n, k;
int factorial(int num) {
	if (num == 0) return 1;
	int res = 1;
	for (int i = num; i >= 1; i--)
		res *= i;
	return res;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	cout << factorial(n) / factorial(k) / factorial(n - k) << "\n";
}