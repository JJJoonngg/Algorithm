/*
����
������ �Ϲ������� 3���� ǥ������� ǥ���� �� �ִ�. 
�����ڰ� �ǿ����� ��� ��ġ�ϴ� ���� ǥ���(�Ϲ������� �츮�� ���� ����̴�), 
�����ڰ� �ǿ����� �տ� ��ġ�ϴ� ���� ǥ���(prefix notation), �����ڰ� �ǿ����� �ڿ� ��ġ�ϴ� 
���� ǥ���(postfix notation)�� �װ��̴�. ���� ��� ���� ǥ������� ǥ���� a+b�� ���� ǥ������δ� +ab�̰�, ���� ǥ������δ� ab+�� �ȴ�.
�� �������� �츮�� �ٷ� ǥ����� ���� ǥ����̴�. ���� ǥ����� ������ ���� ���� ���� �����ڰ� �ǿ����� �ڿ� ��ġ�ϴ� ����̴�.
�� ����� ������ ������ ����. �츮�� ���� ���� ���� ǥ��� ���� ��쿡�� ������ ������ �켱������ ���̰� �־� 
���ʺ��� ���ʷ� ����� �� ������ ���� ǥ����� ����ϸ� ������ ������ �����Ͽ� ������ ������ �� �ִ�. 
���� ���� ������� ��ȣ � �ʿ� ���� �ȴ�. ���� ��� a+b*c�� ���� ǥ������� �ٲٸ� abc*+�� �ȴ�.
���� ǥ����� ���� ǥ������� �ٲٴ� ����� ������ �����ϸ� �̷���. �켱 �־��� ���� ǥ����� �������� �켱������ ���� ��ȣ�� �����ش�. 
�׷� ������ ��ȣ ���� �����ڸ� ��ȣ�� ���������� �Ű��ָ� �ȴ�.

���� ��� a+b*c�� (a+(b*c))�� �İ� ���� �ȴ�. �� ������ �ȿ� �ִ� ��ȣ�� ������ *�� ��ȣ ������ ������ �Ǹ� (a+bc*)�� �ȴ�.
���������� �� +�� ��ȣ�� ���������� ��ġ�� abc*+�� �ǰ� �ȴ�.

�Է�
ù° �ٿ� ���� ǥ����� �־�����. �� �� ������ �ǿ����ڴ� A~Z�� ���ڷ� �̷������ ���Ŀ��� �� ������ �����Ѵ�. 
�׸��� -A+B�� ���� -�� ���� �տ� ���ų� AB�� ���� *�� �����Ǵ� ���� ������ �־����� �ʴ´�. 
ǥ����� ���ĺ� �빮�ڿ� +, -, *, /, (, )�θ� �̷���� ������, ���̴� 100�� ���� �ʴ´�.
A*(B+C)

���
ù° �ٿ� ����ǥ������� �ٲ� ���� ����Ͻÿ�
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