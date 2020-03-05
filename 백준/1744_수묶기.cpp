/*
https://www.acmicpc.net/problem/1744
문제
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라,
수열의 두 수를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다.
그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.
예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다.
하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.
수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N이 주어진다. N은 10,000보다 작다. 둘째 줄부터 N개의 줄에, 수열의 각 수가 주어진다.
수열의 수는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이다.
4
-1
2
1
3
출력
수를 적절히 묶어 그 합이 최댓값을 출력한다. 정답은 항상 2^31보다 작다.
6
*/
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int> positive;
	priority_queue<int, vector<int>, greater<int>>negative;
	int n, sum = 0, zero = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp == 1) sum++;
		else if (tmp > 0) positive.push(tmp);
		else if (tmp < 0) negative.push(tmp * (-1));
		else zero++;
	}
	if (positive.size() % 2 == 1) positive.push(1);
	if (negative.size() % 2 == 1) {
		if (!zero) 	sum += negative.top() * (-1);
		negative.pop();
	}
	int psiz = positive.size(), nsiz = negative.size();
	for (int i = 0; i < psiz / 2; i++) {
		int tmp = positive.top(); positive.pop();
		sum += tmp * positive.top();
		positive.pop();
	}

	for (int i = 0; i < nsiz / 2; i++) {
		int tmp = negative.top(); negative.pop();
		sum += tmp * negative.top();
		negative.pop();
	}

	cout << sum << "\n";
}