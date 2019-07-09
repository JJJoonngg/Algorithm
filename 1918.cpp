/*
문제
수식은 일반적으로 3가지 표기법으로 표현할 수 있다. 
연산자가 피연산자 가운데 위치하는 중위 표기법(일반적으로 우리가 쓰는 방법이다), 
연산자가 피연산자 앞에 위치하는 전위 표기법(prefix notation), 연산자가 피연산자 뒤에 위치하는 
후위 표기법(postfix notation)이 그것이다. 예를 들어 중위 표기법으로 표현된 a+b는 전위 표기법으로는 +ab이고, 후위 표기법으로는 ab+가 된다.
이 문제에서 우리가 다룰 표기법은 후위 표기법이다. 후위 표기법은 위에서 말한 법과 같이 연산자가 피연산자 뒤에 위치하는 방법이다.
이 방법의 장점은 다음과 같다. 우리가 흔히 쓰는 중위 표기식 같은 경우에는 덧셈과 곱셈의 우선순위에 차이가 있어 
왼쪽부터 차례로 계산할 수 없지만 후위 표기식을 사용하면 순서를 적절히 조절하여 순서를 정해줄 수 있다. 
또한 같은 방법으로 괄호 등도 필요 없게 된다. 예를 들어 a+b*c를 후위 표기식으로 바꾸면 abc*+가 된다.
중위 표기식을 후위 표기식으로 바꾸는 방법을 간단히 설명하면 이렇다. 우선 주어진 중위 표기식을 연산자의 우선순위에 따라 괄호로 묶어준다. 
그런 다음에 괄호 안의 연산자를 괄호의 오른쪽으로 옮겨주면 된다.

예를 들어 a+b*c는 (a+(b*c))의 식과 같게 된다. 그 다음에 안에 있는 괄호의 연산자 *를 괄호 밖으로 꺼내게 되면 (a+bc*)가 된다.
마지막으로 또 +를 괄호의 오른쪽으로 고치면 abc*+가 되게 된다.

입력
첫째 줄에 중위 표기식이 주어진다. 단 이 수식의 피연산자는 A~Z의 문자로 이루어지며 수식에서 한 번씩만 등장한다. 
그리고 -A+B와 같이 -가 가장 앞에 오거나 AB와 같이 *가 생략되는 등의 수식은 주어지지 않는다. 
표기식은 알파벳 대문자와 +, -, *, /, (, )로만 이루어져 있으며, 길이는 100을 넘지 않는다.
A*(B+C)

출력
첫째 줄에 후위표기식으로 바뀐 식을 출력하시오
ABC+*
*/
#include <iostream>
#include <string>
#include <malloc.h>
#include <cstdio>

using namespace std;

typedef struct StackNode {
	char item;
	struct  StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
}LinkedStackType;

int cnt = 0;
void init(LinkedStackType *s) {
	s->top = NULL;
}
int empty(LinkedStackType *s) {
	if (s->top == NULL) return 1;
	else return 0;
}
void push(LinkedStackType *s, char item) {
	StackNode *tmp = (StackNode *)malloc(sizeof(StackNode));
	if (tmp == NULL) {
		cout << "메모리 할당 에러" << endl;
		return;
	}
	else {
		tmp->item = item;
		tmp->link = s->top;
		s->top = tmp;
		cnt++;
	}
}
char pop(LinkedStackType *s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		StackNode *tmp = s->top;
		char item = tmp->item;
		s->top = s->top->link;
		free(tmp);
		cnt--;
		return item;
	}
}
char top(LinkedStackType *s) {
	if (empty(s) == 1) { return -1; }
	else { return s->top->item; }
}
int size() {
	return cnt;
}
int operationRank(char op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 3;
}
int main() {
	LinkedStackType st;
	init(&st);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			cout << s[i];
		else {
			int rank = operationRank(s[i]);
			if (rank == 0) push(&st, s[i]);
			else if (rank == 1 || rank == 2) {
				while (!empty(&st) && operationRank(top(&st)) >= rank) {
					cout << top(&st);
					pop(&st);
				}
				push(&st,s[i]);
			}
			else {
				while (!empty(&st) && top(&st) != '(') {
					cout << top(&st);
					pop(&st);
				}
				pop(&st);
			}
		}
	}
	while (!empty(&st))
		cout << top(&st), pop(&st);
	cout << endl;
	return 0;
}