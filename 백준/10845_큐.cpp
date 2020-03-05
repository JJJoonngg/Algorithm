/*
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
1
2
2
0
1
2
-1
0
1
-1
0
3
*/
#include <iostream>
#include <string>
using namespace std;
#define MAX 10001

int queue[MAX] = { 0 };
int index = 0;
void push(int data) {
	if (index == MAX) return;
	else {
		queue[index] = data; 
		index++;
	}	
}
int pop() {
	if (index == 0) return -1;
	else {
		int tmp = queue[0];
		for (int i = 0; i < index; i++) {
			queue[i] = queue[i + 1];
		}
		queue[index - 1] = 0;
		index--;
		return tmp;
	}
}
bool empty() {
	if (index == 0) return true;
	else return false;
}
int front() {
	if (queue[0] == 0) return -1;
	else return queue[0];
}
int back() {
	if (queue[0] == 0) return -1;
	else return queue[index - 1];
}
int size() {
	return index;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int data;
			cin >> data;
			push(data);
		}
		else if (s == "pop") {
			cout << pop() << endl;
		}
		else if (s == "size") {
			cout << size() << endl;
		}
		else if (s == "empty") {
			cout << empty() << endl;
		}
		else if (s == "front") {
			cout << front() << endl;
		}
		else if (s == "back") {
			cout << back() << endl;
		}
	}
	return 0;
}