/*
https://www.acmicpc.net/problem/12783
문제
주어진 숫자 카드와 사칙연산, 괄호 등을 조합하여 원하는 값을 만드는 게임이 있다.
이 게임을 좋아하는 ‘진’은 이번 IT공과대학 MT에서 이 게임을 하려고 카드를 챙겼다.
그러나 실수로 카드셋을 다 챙기지 못 했다. 연산자 카드는 오직 곱하기 카드만 챙기고, 숫자카드는 0에서 9까지 카드 중 N개의 종류의 카드만 챙겼다.
그래서 진은 게임의 종류를 곱셈 게임으로 변경하기로 하였다.
곱셈 게임은 정해진 숫자를 주어진 숫자카드와 곱셈카드를 조합하여 만드는 게임이다.
이 게임은 곱셈카드의 개수를 가장 적게 사용하는 팀이 승리하게 된다.
가져온 숫자카드의 종류가 주어졌을 때, 곱셈카드를 가장 적게 사용하여 게임을 승리할 수 있도록 하자.
카드는 각 종류별로 충분히 많이 가져와 부족한 경우는 없다.

예를 들어, 가져온 숫자카드의 종류가 2,3,6 일 때, 64는 32 x 2 로 곱하기 1개를 사용하여 만들 수 있고 이는 곱셈카드를 가장 적게 사용한 것이다.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 50)가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 숫자 카드의 종류의 개수 N(1 ≤ N ≤ 10)과 N개의 숫자 카드의 종류가 공백을 구분으로 주어진다.
각 테스트 케이스의 두 번째 줄에는 질의의 수 M(1 ≤ M ≤ 20)이 주어진다.
다음 M개의 줄에는 만들고자 하는 자연수 K가 주어진다.(K ≤ 1,000,000)
2
3 2 3 6
3
64
5
7
4 1 2 3 4
2
31
16
출력
각 질의마다 곱셈카드의 최소의 개수를 출력한다. 수를 만들 수 없는 경우에는 -1을 출력한다.
1
-1
-1
0
1
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 1e9
#define MAXI 1000000 + 1
using namespace std;
int num[MAXI];
int dp[MAXI];
int t, n, m, res;

void checkMadeByNoneMultiply(int x) {
	if (x == 0 && num[0] == true) { dp[x] = 0; return; }
	bool flag = true;
	int tmp = x;
	while (tmp > 0) {
		if (num[tmp % 10] == false) {
			flag = false;
			break;
		}
		tmp /= 10;
	}
	if (flag) dp[x] = 0;
}
int function(int input) {
	if (dp[input] != -1) return dp[input];
	
	int ans = INF;
	for (int i = 2; i <= sqrt(input); i++)
		if (input%i == 0)
			ans = min(ans, function(i) + function(input / i) + 1);
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(num, false, sizeof(num));
		cin >> n;
		while (n--) {
			int tmp; cin >> tmp;
			num[tmp] = true;
		}
		cin >> m;
		while (m--) {
			int input; cin >> input;
			for (int i = 0; i <= input; i++)
				checkMadeByNoneMultiply(i);

			res = INF;
			res = function(input);
			if (res == INF) res = -1;
			cout << res << "\n";
		}
	}
}