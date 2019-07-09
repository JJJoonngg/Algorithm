/*
�Է��Է�
�Է��� ù �ٿ��� CTP�� ȸ���� N(1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ��ȸ�� ������ ���� �� M(1 �� M �� 1,000)�� ���� �����ϴµ� �ʿ��� ������ �� K(1 �� K �� 10)�� �־�����.
��° �ٿ��� ������ CTP ȸ������ ������ �ִ� ���� �� A(0 �� A �� 100)�� ������ �������� �־�����.
7
36 3
9 70 15 13 19 20 11
���
�����̰� �ּ����� ȸ���鿡�� �������� �� ��, ���� ȸ���� ���� ����Ѵ�.
���� ���� ������ ��� "STRESS"(����ǥ�� ����)�� ����Ѵ�.

3
*/
#include <iostream>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	int res = m * k, cnt = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		pq.push(input);
	}
	while (!pq.empty()) {
		res -= pq.top();
		pq.pop();
		cnt++;
		if (res <= 0) break;
	}
	if (res > 0 && pq.empty()) cout << "STRESS\n";
	else cout << cnt << "\n";

}