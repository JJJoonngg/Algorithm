/*
https://www.acmicpc.net/problem/10871
����
���� N���� �̷���� ���� A�� ���� X�� �־�����. �̶�, A���� X���� ���� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� X�� �־�����. (1 �� N, X �� 10,000)

��° �ٿ� ���� A�� �̷�� ���� N���� �־�����. �־����� ������ ��� 1���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̴�.
10 5
1 10 4 9 2 3 8 5 7 6
���
X���� ���� ���� �Է¹��� ������� �������� ������ ����Ѵ�. X���� ���� ���� ��� �ϳ� �����Ѵ�.
1 4 2 3
*/
#include <iostream>
#include <queue>
using namespace std;
//#define MAX 10001
//int main() {
//	int n, x, tmp = 0, arr[MAX] = { 0, };
//	scanf("%d %d", &n, &x);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &tmp);
//		if (tmp < x) arr[i] = tmp;
//	}
//	for (int i = 0; i < n; i++)
//		if (arr[i] > 0) printf("%d ", arr[i]);
//	printf("\n");
//}
int main() {
	int n, x, tmp = 0;
	queue<int> q;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp < x) q.push(tmp);
	}
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
}