/*
https://www.acmicpc.net/problem/1978
����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.
4
1 3 5 7
���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
3
*/
#include <iostream>
#include <cmath>
int main() {
	int n, cnt = 0, arr[101] = { 0, }, mod[1001] = { 0, };
	scanf("%d", &n);
	for (int i = 2; i <= sqrt(1000); i++) {
		if (mod[i]) continue;
		for (int j = i + i; j <= 1000; j += i)
			mod[j] = true;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1) continue;
		if (!mod[arr[i]]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}