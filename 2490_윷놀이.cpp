/*
https://www.acmicpc.net/problem/2490
문제
우리나라 고유의 윷놀이는 네 개의 윷짝을 던져서 배(0)와 등(1)이 나오는 숫자를 세어 도, 개, 걸, 윷, 모를 결정한다.
네 개 윷짝을 던져서 나온 각 윷짝의 배 혹은 등 정보가 주어질 때 
도(배 한 개, 등 세 개), 개(배 두 개, 등 두 개), 
걸(배 세 개, 등 한 개), 윷(배 네 개), 모(등 네 개) 중 어떤 것인지를 결정하는 프로그램을 작성하라.

입력
첫째 줄부터 셋째 줄까지 각 줄에 각각 한 번 던진 윷짝들의 상태를 나타내는 네 개의 정수(0 또는 1)가  빈칸을 사이에 두고 주어진다.
0 1 0 1
1 1 1 0
0 0 1 1
출력
첫째 줄부터 셋째 줄까지 한 줄에 하나씩 결과를  도는 A, 개는 B, 걸은 C, 윷은 D, 모는 E로 출력한다.
B
A
B
알고리즘 분류 : 구현
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 3;
	while (t--) {
		int n = 4;
		int res = 0;
		while (n--) {
			int input; cin >> input;
			res += input;
		}
		if (res == 3) cout << "A\n";
		else if (res == 2) cout << "B\n";
		else if (res == 1) cout << "C\n";
		else if (res == 0) cout << "D\n";
		else if (res == 4) cout << "E\n";
	}
}