/*
����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.
�־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

14
push 1
push 2
top
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
top
���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
2
2
0
2
1
-1
0
1
-1
0
3
*/
#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <string>
using namespace std;
int cnt = 0;
typedef struct StackNode {
	int item;
	struct  StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
}LinkedStackType;

void init(LinkedStackType *s) {
	s->top = NULL;
}
int empty(LinkedStackType *s) {
	if (s->top == NULL) return 1;
	else return 0;
}
void push(LinkedStackType *s, int item) {
	StackNode *tmp = (StackNode *)malloc(sizeof(StackNode));
	if (tmp == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	else {
		tmp->item = item;
		tmp->link = s->top;
		s->top = tmp;
		cnt++;
	}
}
int pop(LinkedStackType *s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		StackNode *tmp = s->top;
		int item = tmp->item;
		s->top = s->top->link;
		free(tmp);
		cnt--;
		return item;
	}
}
int top(LinkedStackType *s) {
	if (empty(s) == 1) { return -1; }
	else { return s->top->item; }
}
int size() {
	return cnt;
}
int main() {
	LinkedStackType s;
	init(&s);
	int n;
	cin >> n;
	while (n--) {
		string command;
		int data;
		cin >> command;
		if (command == "push") {
			scanf("%d", &data);
			push(&s, data);
		}
		else if (command == "pop") printf("%d\n", pop(&s));
		else if (command == "size") printf("%d\n", size());
		else if (command == "empty") printf("%d\n", empty(&s));
		else if (command == "top") printf("%d\n", top(&s));
	}
	return 0;
}