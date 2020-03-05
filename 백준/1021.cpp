/*
문제
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.
1.첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
2.왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
3.오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.

큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. 
(이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 
둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.
10 3
1 2 3

출력
첫째 줄에 문제의 정답을 출력한다.
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