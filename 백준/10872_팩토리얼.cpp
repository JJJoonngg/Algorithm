/*
https://www.acmicpc.net/problem/10872
����
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.
10
���
ù° �ٿ� N!�� ����Ѵ�.
3628800
*/
#include <iostream>
int main() {
	int n, arr[13];
	arr[0] = 1;
	for (int i = 1; i < 13; i++) arr[i] = i * arr[i - 1];
	scanf("%d", &n);
	printf("%d\n", arr[n]);
}