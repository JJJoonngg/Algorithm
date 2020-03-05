/*
https://www.acmicpc.net/problem/2609
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.
24 18
출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
6
72
*/
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x, int y) {
	if (y > x) swap(x, y);
	int mod = x % y;
	while (mod) {
		x = y;
		y = mod;
		mod = x % y;
	}
	return y;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int G = gcd(a, b);
	int L = a / G * b / G * G;
	cout << G << "\n" << L << "\n";
}