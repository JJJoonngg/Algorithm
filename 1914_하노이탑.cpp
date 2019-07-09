/*
https://www.acmicpc.net/problem/1914
����
�� ���� ��밡 �ְ� ù ��° ��뿡�� �ݰ��� ���� �ٸ� n���� ������ �׿� �ִ�. �� ������ �ݰ��� ū ������� �׿��ִ�. 
���� �����µ��� ���� ��Ģ�� ���� ù ��° ��뿡�� �� ��° ����  �ű�� �Ѵ�.

�� ���� �� ���� ���Ǹ��� �ٸ� ž���� �ű� �� �ִ�.
�׾� ���� ������ �׻� ���� ���� �Ʒ��� �ͺ��� �۾ƾ� �Ѵ�.(�߰� ���� ���� �׷�����)
�� �۾��� �����ϴµ� �ʿ��� �̵������� ����ϴ� ���α׷��� �ۼ��϶�
�Է�
ù° �ٿ� ù ��° ��뿡 ���� ������ ���� N (1 �� N �� 100)�� �־�����.
3
���
ù° �ٿ� �ű� Ƚ�� K�� ����Ѵ�.
N�� 20 ������ �Է¿� ���ؼ��� �� ��° �ٺ��� ���� ������ ����Ѵ�. �� ��° �ٺ��� K���� �ٿ� ���� �� ���� A B�� ��ĭ�� ���̿� �ΰ� ����ϴµ�, 
�̴� A��° ž�� ���� ���� �ִ� ������ B��° ž�� ���� ���� �ű�ٴ� ���̴�. (N�� 20���� ū ��쿡�� ������ ����� �ʿ䰡 ����.)
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define MAX 1000000
using namespace std;
int n;
long long cnt;
void hanoi(int num, int from, int by, int to) {
	if (num == 1) printf("%d %d\n", from, to);
	else {
		hanoi(num - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(num - 1, by, from, to);
	}
}

int main() {
	scanf("%d", &n);
	char result[MAX];
	long double  tmp;
	tmp = pow(2, n);
	sprintf(result, "%.0Lf", tmp);
	int size = strlen(result);
	result[size - 1] = (char)(((int)(result[size - 1] - 48) - 1) + 48);
	printf("%s\n", result);
	if (n <= 20) {
		hanoi(n, 1, 2, 3);
	}
}