/*
https://www.acmicpc.net/problem/1427
문제
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

입력
첫째 줄에 정렬하고자하는 수 N이 주어진다.
N은 1,000,000,000보다 작거나 같은 자연수이다.
2143
출력
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
4321
알고리즘 분류 : 정렬
*/
#include <iostream>
#include <queue>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int> pq;
	int n; cin >> n;
	while (n > 0) {
		int tmp = n % 10;
		pq.push(tmp);
		n /= 10;
	}
	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	cout << "\n";
}