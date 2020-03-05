/*
문제
여러분도 알다시피 여러분의 프린터 기기는 여러분이 인쇄하고자 하는 문서를 인쇄 명령을 받은 ‘순서대로’, 즉 먼저 요청된 것을 먼저 인쇄한다. 
여러 개의 문서가 쌓인다면 Queue 자료구조에 쌓여서 FIFO - First In First Out - 에 따라 인쇄가 되게 된다. 
하지만 상근이는 새로운 프린터기 내부 소프트웨어를 개발하였는데, 이 프린터기는 다음과 같은 조건에 따라 인쇄를 하게 된다.
현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
예를 들어 Queue에 4개의 문서(A B C D)가 있고, 중요도가 2 1 4 3 라면 C를 인쇄하고, 다음으로 D를 인쇄하고 A, B를 인쇄하게 된다.
여러분이 할 일은, 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 때, 어떤 한 문서가 몇 번째로 인쇄되는지 알아내는 것이다. 
예를 들어 위의 예에서 C문서는 1번째로, A문서는 3번째로 인쇄되게 된다.

입력
첫 줄에 test case의 수가 주어진다. 각 test case에 대해서 문서의 수 N(100이하)와 몇 번째로 인쇄되었는지
궁금한 문서가 현재 Queue의 어떤 위치에 있는지를 알려주는 M(0이상 N미만)이 주어진다. 다음줄에 N개 문서의 중요도가 주어지는데,
중요도는 적절한 범위의 int형으로 주어진다. 중요도가 같은 문서가 여러 개 있을 수도 있다. 위의 예는 N=4, M=0(A문서가 궁금하다면), 중요도는 2 1 4 3이 된다.
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
출력
각 test case에 대해 문서가 몇 번째로 인쇄되는지 출력한다.
1
2
5
*/
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 101
void swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

class Queue {
private:
	int r, f;
	int index;
	int _size;
	int* queue;
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
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int test;
	cin >> test;

	while (test--) {
		int N, M;
		cin >> N >> M;
		PriorityQueue pq;
		Queue q(N + 1);
		Queue check(N + 1);
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			pq.push(data);
			q.push(data);
			if (i == M) check.push(1);
			else check.push(0);
		}
		int cnt = 0;
		while (!q.is_empty()) {
			int Queue_num = q.front();
			int Checking = check.front();
			int Priority_num = pq.front();
			if (Priority_num == Queue_num) {
				pq.pop();
				q.pop();
				check.pop();
				cnt++;
				if (Checking == 1) break;
			}
			else {
				q.pop();
				q.push(Queue_num);
				check.pop();
				check.push(Checking);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}