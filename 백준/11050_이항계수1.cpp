/*
https://www.acmicpc.net/problem/11050
����
�ڿ��� n�� ���� k�� �־����� �� ���� ���(n,k) �� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� �� �־�����. (1 �� n �� 10, 0 �� k �� n)
5 2
���
(n,k)�� ����Ѵ�.
10
*/
#include <iostream>
using namespace std;
int n, k;
int factorial(int num) {
	if (num == 0) return 1;
	int res = 1;
	for (int i = num; i >= 1; i--)
		res *= i;
	return res;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	cout << factorial(n) / factorial(k) / factorial(n - k) << "\n";
}