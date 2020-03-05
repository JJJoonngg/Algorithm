/*
https://www.acmicpc.net/problem/11720
문제
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.
1
1

5
54321

25
7000000000000000000000000

11
10987654321
출력
입력으로 주어진 숫자 N개의 합을 출력한다.
1
15
7
46

알고리즘 분류 : 출력
*/
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, sum =0; cin >> n;
	char arr[101] = { 0, };
	cin >> arr;

	for (int i = 0; i < n; i++) sum += arr[i] - '0';
	
	cout << sum << "\n";
}