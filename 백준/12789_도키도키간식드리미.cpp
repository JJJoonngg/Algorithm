/*
�Է�
�Է��� ù° �ٿ��� ���� ��ȯ���� �տ� �� �ִ� �л����� �� N(1 �� N �� 1,000,�ڿ���)�� �־�����.
���� �ٿ��� ��ȯ�� �տ� ���ִ� ��� �л����� ��ȣǥ(1,2,...,N) ������ �տ������� �� ������ �־�����.
5
5 4 1 3 2

���
��ȯ�̰� ������ ������ ���� �� ������ "Nice"(����ǥ�� ����)�� ����ϰ� �׷��� �ʴٸ� "Sad"(����ǥ�� ����)�� ����Ѵ�.
Nice
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	stack<int> s;
	queue<int> q;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	int start = 1;

	for (int i = 0; i < N; i++) {
		if (q.front() == start) {
			q.pop();
			start++;
		}
		else {
			if (!s.empty()) {
				if (s.top() == start) {
					s.pop();
					start++;
					i--;
					continue;
				}
			}
			s.push(q.front());
			q.pop();
		}
	}


	while (!s.empty()) {
		if (start == s.top()) {
			s.pop();
			start++;
		}
		else break;
	}
	if (s.empty()) cout << "Nice" << endl;
	else cout << "Sad" << endl;

	return 0;
}