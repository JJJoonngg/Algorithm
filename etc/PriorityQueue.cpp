#include <iostream>
#define MAX 9999
using namespace std;

//priority_queue<int, vector<int>, greater<int>> num; 우선순위 큐 오름차순
//#include <functional> 헤더

void swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

class PriorityQueue {
private:
	int index = 0;
	int priority_queue[MAX];
public:
	bool empty() {
		if (index == 0) return true;
		else return false;
	}
	int front() {
		if (empty()) return -1;
		else return priority_queue[1];
	}
	int size() {
		return index;
	}
	void push(int data) {
		if (index == MAX) return;
		else if (index == 0) priority_queue[++index] = data;
		else {
			priority_queue[++index] = data;
			int tmp = index;
			int parent = index / 2;
			if (parent == 0) return;

			while (priority_queue[parent] < priority_queue[tmp] && parent != 0) {
				swap(priority_queue, parent, tmp);
				tmp /= 2;
				parent = tmp / 2;
			}
		}
	}

	void pop() {
		if (empty())  cout << "Queue is empty" << endl;
		else {
			priority_queue[1] = priority_queue[index];
			int tmp = 1; int left = 2; int right = 3;
			while (priority_queue[tmp] < priority_queue[left] ||
				priority_queue[tmp] < priority_queue[right]) {

				if (left > index) left = 0;
				if (right > index) right = 0;
				if (left == 0 && right == 0) break;

				if (priority_queue[left] < priority_queue[right]) {
					swap(priority_queue, tmp, right);
					tmp = right;
				}
				else {
					swap(priority_queue, tmp, left);
					tmp = left;
				}
				left = tmp * 2;
				right = tmp * 2 + 1;
			}
			index--;
		}
	}
};
int main() {
	PriorityQueue pq;
	pq.push(7);
	pq.push(4);
	pq.push(8);
	pq.push(2);
	pq.push(5);
	pq.push(3);
	pq.push(9);

	while (!pq.empty()) {
		cout << pq.front() << endl;
		pq.pop();
	}

	return 0;
}