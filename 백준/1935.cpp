/*
문제
얼마전에 후위표기식에 관한 프로그래밍을 한 적이 있다. 
이제 후위 표기식과 각 피 연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램을 작성하시오.

입력
첫째 줄에 피 연산자의 개수(1<=N<=26) 가 주어진다. 그리고 둘째 줄에는 후위표기식이 주어진다. 
(여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며, 길이는 100을 넘지 않는다) 
그리고 셋째 줄부터 3+N줄까지는 각 피 연산자에 대응하는 값이 주어진다. (3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 , 
5번째 줄에는 C ...이 주어진다, 그리고 피 연산자에 대응 하는 값은 정수이다)
5
ABC*+DE/-
1
2
3
4
5

1
AA+A+
1
출력
계산 결과를 출력한다. (계산 결과를 소숫점 둘째 자리까지 출력하시오)
6.20
3.00
*/
#include <iostream>
#include <string>
#include <malloc.h>
#include <cstdio>

using namespace std;

typedef struct StackNode {
	double item;
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
void push(LinkedStackType *s, double item) {
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
double pop(LinkedStackType *s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		StackNode *tmp = s->top;
		double item = tmp->item;
		s->top = s->top->link;
		free(tmp);
		cnt--;
		return item;
	}
}
double top(LinkedStackType *s) {
	if (empty(s) == 1) { return -1; }
	else { return s->top->item; }
}
int size() {
	return cnt;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	LinkedStackType st;
	init(&st);
	int n;
	double var[27];
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) cin >> var[i];
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			push(&st, var[s[i]-'A']);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			double a = top(&st); pop(&st);
			double b = top(&st); pop(&st);
			switch (s[i]) {
			case '+':
				push(&st, b + a);
				break;
			case '-':
				push(&st, b - a);
				break;
			case '*':
				push(&st, b * a);
				break;
			case '/':
				push(&st, b / a);
				break;
			}
		}
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << top(&st) << endl;

	return 0;
}