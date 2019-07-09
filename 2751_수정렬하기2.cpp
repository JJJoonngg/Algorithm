/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
5
5
4
3
2
1
출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
1
2
3
4
5
*/
#include <iostream>
#include <queue>
using namespace std;
struct compare { bool operator()(int& l, int &r) { return l > r; } };
int main() {
	int n;
	priority_queue<int, vector<int>, compare> pq;
	scanf("%d", &n);
	while(n--){
		int tmp;
		scanf("%d", &tmp);
		pq.push(tmp);
	}
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
	return 0;
}