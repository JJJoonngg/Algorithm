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
		else return deque[r];
	}
	int size() {
		return _size;
	}

};

int main() {
	Deque dq(4);

	dq.push_front(10);
	dq.push_front(20);
	dq.push_back(30);

	for (int i = 0; i < 3; i++) {cout<< dq.pop_front()<<endl; }

	dq.push_front(10);
	dq.push_front(20);
	dq.push_back(30);
	
	for (int i = 0; i < 3; i++) { cout << dq.pop_back() << endl; }

	return 0;
}