/*
https://www.acmicpc.net/problem/5525
문제
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.

P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O가 N개)
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다. (1 ≤ N ≤ 1,000,000, 2N+1 ≤ M ≤ 1,000,000)
1
13
OOIOIOIOIIOII
출력
S에 PN이 몇 군데 포함되어 있는지 출력한다.
4
문자열 검색 kmp알고리즘 참조
*/
#include <iostream>
#include <string>
#define MAX 1000001
using namespace std;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, length, cnt = 0;
	string s;
	cin >> n >> length >> s;
	for (int i = 0; i < length; i++) {
		if (s[i + 1] == 'O' && s[i + 2] == 'I') {
			int tmp = 0;
			while (s[i] == 'I' && s[i + 1] == 'O') {
				i += 2; tmp++;
				if (s[i] == 'I' && tmp == n) {
					tmp--; cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
}