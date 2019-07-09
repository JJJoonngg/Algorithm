/*
https://www.acmicpc.net/problem/10989
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
10
5
2
3
1
4
2
3
5
1
7

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
1
1
2
2
3
3
4
5
5
7
알고리즘 분류 : 정렬
*/
#include <iostream>
using namespace std;
int arr[10001] = { 0, };
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << "\n";
			}
		}
	}
}