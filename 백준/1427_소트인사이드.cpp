/*
https://www.acmicpc.net/problem/1427
����
�迭�� �����ϴ� ���� ����. ���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.

�Է�
ù° �ٿ� �����ϰ����ϴ� �� N�� �־�����.
N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.
2143
���
ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.
4321
�˰��� �з� : ����
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