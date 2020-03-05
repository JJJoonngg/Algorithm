/*
입력
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 50)가 주어진다.
각 테스트케이스의 첫 번째 줄에는 두 이진수 N, M이 주어진다.
N, M의 자릿수는 1,000,000을 넘지 않으며, 자릿수는 서로 같다.
3
1011 1100
100101 110100
00110100 10010111
출력
각 테스트 케이스마다 두 수의 비트 우정지수를 출력한다.
2
1
3
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string n, m;
		cin >> n >> m;
		if (n == m) cout << "0\n";
		else {
			int Ncnt = 0, Mcnt = 0;
			for (int i = 0; n[i] != '\0'; i++) {
				if (n[i] == '0') Ncnt++;
				if (m[i] == '0') Mcnt++;
			}
		}
	}
}