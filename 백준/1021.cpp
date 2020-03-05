/*
����
�����̴� N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť�� ������ �ִ�. �����̴� �� ť���� �� ���� ���Ҹ� �̾Ƴ����� �Ѵ�.

�����̴� �� ť���� ������ ���� 3���� ������ ������ �� �ִ�.
1.ù ��° ���Ҹ� �̾Ƴ���. �� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
2.�������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
3.���������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak-1�� �ȴ�.

ť�� ó���� ���ԵǾ� �ִ� �� N�� �־�����. �׸��� �����̰� �̾Ƴ����� �ϴ� ������ ��ġ�� �־�����. 
(�� ��ġ�� ���� ó�� ť������ ��ġ�̴�.) �̶�, �� ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ť�� ũ�� N�� �̾Ƴ����� �ϴ� ���� ���� M�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̰�, M�� N���� �۰ų� ���� �ڿ����̴�. 
��° �ٿ��� �����̰� �̾Ƴ����� �ϴ� ���� ��ġ�� ������� �־�����. ��ġ�� 1���� ũ�ų� ����, N���� �۰ų� ���� �ڿ����̴�.
10 3
1 2 3

���
ù° �ٿ� ������ ������ ����Ѵ�.
0
*/
#include <iostream>
using namespace std;

class Deque {
private:
	int r, f;
	int index;
	int _size;
public:
	int* deque;
	Deque(int s) {
		deque = new int[s];
		index = s;
		_size = 0;
		r = 0;
		f = 0;
		for (int i = 0; i < s; i++) deque[i] = 0;
	}
	bool is_empty() {
		if (r == f) return 1;
		else return 0;
	}
	bool is_full() {
		if ((r + 1) % index == f) return 1;
		else return 0;
	}
	void push_back(int data) {
		if (is_full()) return;
		else {
			r = (r + 1) % index;
			deque[r] = data;
			_size++;
		}
	}
	void push_front(int data) {
		if (is_full()) return;
		else {
			deque[f] = data;
			f = (f - 1 + index) % index;
			_size++;
		}
	}
	int pop_front() {
		if (is_empty()) return -1;
		else {
			f = (f + 1) % index;
			_size--;
			return deque[f];
		}
	}
	int pop_back() {
		if (is_empty()) return -1;
		else {
			int tmp = deque[r];
			r = (r - 1 + index) % index;
			_size--;
			return tmp;
		}
	}
	int front() {
		if (is_empty()) return -1;
		else return deque[(f + 1) % index];
	}
	int back() {
		if (is_empty()) return -1;
		else return deque[r - 1];
	}
	int size() {
		return _size;
	}

};


int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m, cnt = 0;

	cin >> n >> m;
	Deque dq(n + 1);
	int* arr = new int[m];

	for (int i = 1; i <= n; i++) { dq.push_back(i); }

	for (int i = 0; i < m; i++) { cin >> arr[i]; }
	
	for (int i = 0; i < m; i++) {
		while (true) {
			int cur = 0;
			if (arr[i] == dq.front()) {
				dq.pop_front();
				break;
			}
			for (int j = 1; j <= dq.size(); j++) {
				int tmp = dq.pop_front();
				if (arr[i] == tmp) cur = j;
				dq.push_back(tmp);
			}
			int tmp_left = cur ;
			int tmp_right = dq.size() - cur - 1;

			if (tmp_left <= tmp_right) {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				cnt++;
			}
			else if (tmp_left > tmp_right) {
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	delete[] arr;
	return 0;
}