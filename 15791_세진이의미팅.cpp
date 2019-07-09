/*
https://www.acmicpc.net/problem/15791
문제
모태 솔로인 세진이는 이번에는 꼭 여자친구를 사귀어야겠다는 마음으로 형진이가 주최한 미팅에 참석하게 된다.
하지만 안타깝게도 컴퓨터공학과는 남초학과이기 때문에 항상 남자의 수가 여자의 수보다 많거나 같다.
마음이 급해진 세진이는 항상 모든 여자들이 남자들과 짝을 이루어진다고 가정하였을 때
남자들이 미팅에서 여자들에게 선택되는 모든 경우를 시뮬레이션 해보려고 한다.
예를들어 남자 3명 여자 2명이 있을 때, 남자 1 남자2 가 선택되는 경우, 남자 2 남자 3이 선택되는 경우,
남자1 남자3 이 선택되는 경우로 경우의 수는 3가지가 존재한다.
세진이를 도와 미팅에서 선택될 수 있는 남자들의 모든 상태의 경우의 수를 구해보자.

단, 수가 너무 커질 수 있으니 1000000007로 나눈 나머지를 구해보자.

입력
입력의 첫째 줄에 남학생의 수 N(2 ≤ N ≤ 1000000)명 여학생의 수 M(1 ≤ M ≤ N)명이 주어진다.
3 2
5 2
출력
경우의 수를 1000000007로 나눈 나머지를 출력하라.
3
10
*/
#include <iostream>
#define mod 1000000007
using namespace std;
long long factorial[1000001];
long long n, m, x, y, tmp;
void cal(long long a, long long b) {
	if (a%b > 0) {
		cal(b, a%b);
		tmp = y;
		y = x - (a / b)*y;
		x = tmp;
	}
	else {
		x = 0;
		y = 1;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	factorial[0] = 1; factorial[1] = 1;
	for (int i = 2; i <= n; i++) factorial[i] = factorial[i - 1] * i % mod;
	long long denominator = factorial[m] * factorial[n - m] % mod;

	cal(mod, denominator);
	long long res = (factorial[n] % mod) * (y%mod) % mod;

	if (res < 0) res += mod;
	cout << res << "\n";
}