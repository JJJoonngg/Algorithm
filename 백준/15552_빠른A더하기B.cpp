/*
�Է�
ù �ٿ� �׽�Ʈ���̽��� ���� T�� �־�����. T�� �ִ� 1,000,000�̴�. ���� T�ٿ��� ���� �� ���� A�� B�� �־�����. A�� B�� 1 �̻�, 1,000 �����̴�.
5
1 1
12 34
5 500
40 60
1000 1000
���
�� �׽�Ʈ���̽����� A+B�� �� �ٿ� �ϳ��� ������� ����Ѵ�
2
46
505
100
2000
*/
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
}