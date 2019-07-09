#include <iostream>
#include <string>
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
};
int main() {
	int n, tmp;
	cin >> n;
	Queue card(n+1);
	for (int i = 1; i <= n; i++) {
		card.push(i);
	}
	while (card.size() != 1) {
		card.pop();
		tmp = card.front();
		card.pop();
		card.push(tmp);
	}
	cout << card.front() << endl;
	return 0;
}