/*
https://www.acmicpc.net/problem/15791
����
���� �ַ��� �����̴� �̹����� �� ����ģ���� ��;�߰ڴٴ� �������� �����̰� ������ ���ÿ� �����ϰ� �ȴ�.
������ ��Ÿ���Ե� ��ǻ�Ͱ��а��� �����а��̱� ������ �׻� ������ ���� ������ ������ ���ų� ����.
������ ������ �����̴� �׻� ��� ���ڵ��� ���ڵ�� ¦�� �̷�����ٰ� �����Ͽ��� ��
���ڵ��� ���ÿ��� ���ڵ鿡�� ���õǴ� ��� ��츦 �ùķ��̼� �غ����� �Ѵ�.
������� ���� 3�� ���� 2���� ���� ��, ���� 1 ����2 �� ���õǴ� ���, ���� 2 ���� 3�� ���õǴ� ���,
����1 ����3 �� ���õǴ� ���� ����� ���� 3������ �����Ѵ�.
�����̸� ���� ���ÿ��� ���õ� �� �ִ� ���ڵ��� ��� ������ ����� ���� ���غ���.

��, ���� �ʹ� Ŀ�� �� ������ 1000000007�� ���� �������� ���غ���.

�Է�
�Է��� ù° �ٿ� ���л��� �� N(2 �� N �� 1000000)�� ���л��� �� M(1 �� M �� N)���� �־�����.
3 2
5 2
���
����� ���� 1000000007�� ���� �������� ����϶�.
3
10
*/
#include <iostream>
#define mod 1000000007
using namespace std;
long long factorial[1000001];
long long n, m, x, y, tmp;
void cal(long long a, long long b) {
	if (a%b > 0) {
		cal(b, a%b);
		tmp = y;
		y = x - (a / b)*y;
		x = tmp;
	}
	else {
		x = 0;
		y = 1;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	factorial[0] = 1; factorial[1] = 1;
	for (int i = 2; i <= n; i++) factorial[i] = factorial[i - 1] * i % mod;
	long long denominator = factorial[m] * factorial[n - m] % mod;

	cal(mod, denominator);
	long long res = (factorial[n] % mod) * (y%mod) % mod;

	if (res < 0) res += mod;
	cout << res << "\n";
}