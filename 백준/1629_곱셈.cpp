/*
����
�ڿ��� A�� B�� ���� ���� �˰� �ʹ�. �� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A, B, C�� �� ĭ�� ���̿� �ΰ� ������� �־�����. A, B, C�� ��� 2,147,483,647 ������ �ڿ����̴�.
10 11 12
���
ù° �ٿ� A�� B�� ���� ���� C�� ���� �������� ����Ѵ�
4
*/
#include <iostream>
using namespace std;
long long a, b, c;
long long pow(long long n, long long m) {
	if (m == 0) return 1;
	long long tmp = pow(n, m / 2);
	long long result = tmp * tmp % c;
	if (m % 2) result = result * n % c;
	return result;
}
int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", pow(a, b));
}