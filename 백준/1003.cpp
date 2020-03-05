/*
문제
다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때,
0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.


입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.
3
0
1
3
출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
1 0
0 1
1 2
*/
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		int dp_zero[41] = { 1,0, };
		int dp_one[41] = { 0,1, };
		for (int i = 2; i < 41; i++) {
			dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
			dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
		}
		cin >> n;
		cout << dp_zero[n] << " " << dp_one[n] << endl;
	}
	return 0;
}
