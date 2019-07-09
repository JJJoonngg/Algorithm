/*
두 이진수의 곱

입력
첫 번째 줄에 이진수 B1이 주어진다. 두 번째 줄에 이진수 B2가 주어진다. 입력으로 주어지는 두 이진수의 길이는 1 이상 30 이하의 자연수이다. 또한 두 이진수들이 1로 시작하는 것이 보장된다.
1010
11

1000
100
출력
첫 번째 줄에 입력으로 주어진 두 이진수 B1, B2의 곱을 이진수로 출력한다. 출력하는 이진수 앞에 불필요한 0이 붙으면 안 됨에 주의해야 한다. 즉 출력하는 이진수의 시작은 항상 1이어야 한다.
11110
100000
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	string b1, b2; cin >> b1 >> b2;
	string res ="";
	long long a1 = 0, a2 = 0;
	int tmp = 1;
	for (int i = b1.length() - 1; i >= 0; i--) {
		a1 += (int)(b1[i] - '0') * tmp;
		tmp *= 2;
	}
	tmp = 1;
	for (int i = b2.length() - 1; i >= 0; i--) {
		a2 += (int)(b2[i] - '0') * tmp;
		tmp *= 2;
	}
	long long ans = a1 * a2;
	while (ans) {
		res += (ans % 2 + '0');
		ans /= 2;
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
}