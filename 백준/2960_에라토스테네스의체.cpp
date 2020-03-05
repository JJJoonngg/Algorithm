/*
문제
에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾는 유명한 알고리즘이다.
이 알고리즘은 다음과 같다.
1.2부터 N까지 모든 정수를 적는다.
2.아직 지우지 않은 숫자 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
3.P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
4.아직 모든 숫자를 지우지 않았다면, 다시 2번 단계로 간다.

N, K가 주어졌을 때, K번째 지우는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N, max(2, K) < N ≤ 1000)
10 7

출력
첫째 줄에 K번째 지워진 수를 출력한다.
9

힌트
2, 4, 6, 8, 10, 3, 9, 5, 7 순서대로 지워진다. 7번째 지워진 수는 9이다.

*/
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int n, k, cnt = 0;
	cin >> n >> k;
	int arr[1001];
	memset(arr, 0, sizeof(arr));

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
				cnt++;
			}
			if (cnt == k) {
				cout << j << endl;
				return 0;
			}
		}
	}
	return 0;
}