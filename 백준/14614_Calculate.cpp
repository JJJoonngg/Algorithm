/*
�Է�
�Է��� ù° �ٿ� A,B,C�� �������� ���еǾ� �־�����. (1��A,B��108) (1��C��10100)
1 1 1
3 5 5
���
A�� B�� C�� XOR�� ����� ����Ѵ�.
0 6
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b; string c;
	cin >> a >> b >> c;
	if (c[c.length() - 1] & 1) cout << (a ^ b) << "\n";
	else cout << a << "\n";
}