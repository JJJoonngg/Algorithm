/*
����
�����е� �˴ٽ��� �������� ������ ���� �������� �μ��ϰ��� �ϴ� ������ �μ� ����� ���� ��������Ρ�, �� ���� ��û�� ���� ���� �μ��Ѵ�. 
���� ���� ������ ���δٸ� Queue �ڷᱸ���� �׿��� FIFO - First In First Out - �� ���� �μⰡ �ǰ� �ȴ�. 
������ ����̴� ���ο� �����ͱ� ���� ����Ʈ��� �����Ͽ��µ�, �� �����ͱ�� ������ ���� ���ǿ� ���� �μ⸦ �ϰ� �ȴ�.
���� Queue�� ���� �տ� �ִ� ������ ���߿䵵���� Ȯ���Ѵ�.
������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �Ѵ�. �׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.
���� ��� Queue�� 4���� ����(A B C D)�� �ְ�, �߿䵵�� 2 1 4 3 ��� C�� �μ��ϰ�, �������� D�� �μ��ϰ� A, B�� �μ��ϰ� �ȴ�.
�������� �� ����, ���� Queue�� �ִ� ������ ���� �߿䵵�� �־����� ��, � �� ������ �� ��°�� �μ�Ǵ��� �˾Ƴ��� ���̴�. 
���� ��� ���� ������ C������ 1��°��, A������ 3��°�� �μ�ǰ� �ȴ�.

�Է�
ù �ٿ� test case�� ���� �־�����. �� test case�� ���ؼ� ������ �� N(100����)�� �� ��°�� �μ�Ǿ�����
�ñ��� ������ ���� Queue�� � ��ġ�� �ִ����� �˷��ִ� M(0�̻� N�̸�)�� �־�����. �����ٿ� N�� ������ �߿䵵�� �־����µ�,
�߿䵵�� ������ ������ int������ �־�����. �߿䵵�� ���� ������ ���� �� ���� ���� �ִ�. ���� ���� N=4, M=0(A������ �ñ��ϴٸ�), �߿䵵�� 2 1 4 3�� �ȴ�.
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
���
�� test case�� ���� ������ �� ��°�� �μ�Ǵ��� ����Ѵ�.
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