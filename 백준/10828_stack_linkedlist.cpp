/*
문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

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
출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
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
		printf("메모리 할당 에러\n");
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