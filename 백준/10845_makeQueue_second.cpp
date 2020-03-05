#include <iostream>
#include <string>

#define MAX 10001

using namespace std;

class Queue {
private:
	int r, f;
	int* queue;
	int index;
	int _size;
public:
	Queue(int s) {
		queue = new int[s];
		index = s;
		_size = 0;
		r = 0;
		f = 0;
		for (int i = 0; i < s; i++) queue[i] = 0;
	}
	bool is_empty() {
		if (r == f) return 1;
		else return 0;
	}
	bool is_full() {
		if ((r + 1) % index == f) return 1;
		else return 0;
	}
	void push(int data) {
		if (is_full()) return;
		else {
			r = (r + 1) % index;
			queue[r] = data;
			_size++;
		}
	}
	int pop() {
		if (is_empty()) return -1;
		else {
			f = (f + 1) % index;
			_size--;
			return queue[f];
		}
	}
	int size() {
		return _size;
	}
	int front() {
		if (is_empty()) return -1;
		else return queue[(f + 1) % index];
	}
	int back() {
		if (is_empty()) return -1;
		else return queue[r];
	}
};
int main() {
	int n;
	cin >> n;
	Queue q(n + 1);
	while (n--) {
		string input;
		cin >> input;
		if (input == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (input == "front") {
			cout << q.front() << endl;
		}
		else if (input == "back") {
			cout << q.back() << endl;
		}
		else if (input == "size") {
			cout << q.size() << endl;
		}
		else if (input == "pop") {
			cout << q.pop() << endl;
		}
		else if (input == "empty") {
			cout << q.is_empty() << endl;
		}
	}
	return 0;
}