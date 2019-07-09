/*
����
������ ����ǥ��Ŀ� ���� ���α׷����� �� ���� �ִ�. 
���� ���� ǥ��İ� �� �� �����ڿ� �����ϴ� ������ �־��� ���� ��, �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� �������� ����(1<=N<=26) �� �־�����. �׸��� ��° �ٿ��� ����ǥ����� �־�����. 
(���⼭ �ǿ����ڴ� A~Z�� ���빮���̸�, A���� ������� N���� ���빮�ڸ��� ���Ǹ�, ���̴� 100�� ���� �ʴ´�) 
�׸��� ��° �ٺ��� 3+N�ٱ����� �� �� �����ڿ� �����ϴ� ���� �־�����. (3��° �ٿ��� A�� �ش��ϴ� ��, 4��° �ٿ��� B�� �ش��ϴ°� , 
5��° �ٿ��� C ...�� �־�����, �׸��� �� �����ڿ� ���� �ϴ� ���� �����̴�)
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
���
��� ����� ����Ѵ�. (��� ����� �Ҽ��� ��° �ڸ����� ����Ͻÿ�)
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
		cout << "�޸� �Ҵ� ����" << endl;
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