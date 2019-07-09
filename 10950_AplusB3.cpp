/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
5
1 1
2 3
3 4
9 8
5 2

출력
각 테스트 케이스마다 A+B를 출력한다.
2
5
7
17
7
*/
#include <iostream>
using namespace std;
int main() {
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}