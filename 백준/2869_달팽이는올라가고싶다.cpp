/*
����
�� ���� �����̰� �ִ�. �� �����̴� ���̰� V������ ���� ���븦 �ö� ���̴�.
�����̴� ���� A���� �ö� �� �ִ�. ������, �㿡 ���� �ڴ� ���� B���� �̲�������. ��, ���� �ö� �Ŀ��� �̲������� �ʴ´�.
�����̰� ���� ���븦 ��� �ö󰡷���, ��ĥ�� �ɸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� A, B, V�� �������� ���еǾ �־�����. (1 �� B < A �� V �� 1,000,000,000)
2 1 5
���
ù° �ٿ� �����̰� ���� ���븦 ��� �ö󰡴µ� ��ĥ�� �ɸ����� ����Ѵ�.
4
*/
#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;
int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	long long start = 0, end = v / (a - b) + 1;
	long long mid, res = MAX;
	while(start <= end) {
		mid = (start + end) / 2;
		if (mid*(a - b) + a >= v) {
			res = min(res, mid + 1);
			end = mid - 1;
		}
		else start = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}