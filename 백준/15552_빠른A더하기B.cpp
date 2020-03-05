/*
입력
첫 줄에 테스트케이스의 개수 T가 주어진다. T는 최대 1,000,000이다. 다음 T줄에는 각각 두 정수 A와 B가 주어진다. A와 B는 1 이상, 1,000 이하이다.
5
1 1
12 34
5 500
40 60
1000 1000
출력
각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다
2
46
505
100
2000
*/
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
}