/*
https://www.acmicpc.net/problem/9498
����
���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ������ �־�����. ���� ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.
100
���
���� ������ ����Ѵ�.
A
*/
#include <iostream>
int main() {
	int score;
	scanf("%d", &score);
	if (90 <= score && score <= 100) printf("A\n");
	else if (80 <= score && score <= 89) printf("B\n");
	else if (70 <= score && score <= 79) printf("C\n");
	else if (60 <= score && score <= 69) printf("D\n");
	else printf("F\n");
}