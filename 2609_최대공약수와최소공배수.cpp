/*
https://www.acmicpc.net/problem/2609
����
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.
24 18
���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������,��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.
6
72
*/
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x, int y) {
	if (y > x) swap(x, y);
	int mod = x % y;
	while (mod) {
		x = y;
		y = mod;
		mod = x % y;
	}
	return y;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int G = gcd(a, b);
	int L = a / G * b / G * G;
	cout << G << "\n" << L << "\n";
}