/*
https://www.acmicpc.net/problem/2576
문제
7개의 자연수가 주어질 때, 이들 중 홀수인 자연수들을 모두 골라 그 합을 구하고, 고른 홀수들 중 최솟값을 찾는 프로그램을 작성하시오.
예를 들어, 7개의 자연수 12, 77, 38, 41, 53, 92, 85가 주어지면 이들 중 홀수는 77, 41, 53, 85이므로 그 합은
77 + 41 + 53 + 85 = 256 이 되고,

41 < 53 < 77 < 85  이므로 홀수들 중 최솟값은 41이 된다.

입력
입력의 첫째 줄부터 일곱 번째 줄까지 한 줄에 하나의 자연수가 주어진다. 주어지는 자연수는 100보다 작다.
12
77
38
41
53
92
85

2
4
20
32
6
10
8
출력
홀수가 존재하지 않는 경우에는 첫째 줄에 -1을 출력한다. 
홀수가 존재하는 경우 첫째 줄에 홀수들의 합을 출력하고, 둘째 줄에 홀수들 중 최솟값을 출력한다.
256
41

-1
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int input[7], res=0, tmp = 100, check = false;
	for (int i = 0; i < 7; i++) {
		cin >> input[i];
		if (input[i] % 2) {
			check = true;
			res += input[i];
			tmp = min(tmp, input[i]);
		}
	}
	if (!check) cout << "-1\n";
	else cout << res << "\n" << tmp << "\n";
}