/*
https://www.acmicpc.net/problem/1009
����
����̴� �ֽ� ��ǻ�� 10�븦 ������ �ִ�. ��� �� ����̴� ���� �����͸� ó���ؾ� �� ���� ���ܼ�
�� ��ǻ�Ϳ� 1������ 10�������� ��ȣ�� �ο��ϰ�, 10���� ��ǻ�Ͱ� ������ ���� ������� �����͵��� ó���ϱ�� �Ͽ���.
1�� �����ʹ� 1�� ��ǻ��, 2�� �����ʹ� 2�� ��ǻ��, 3�� �����ʹ� 3�� ��ǻ��, ... ,
10�� �����ʹ� 10�� ��ǻ��, 11�� �����ʹ� 1�� ��ǻ��, 12�� �����ʹ� 2�� ��ǻ��, ...

�� �������� ������ �׻� ab���� ���·� �־�����. ����̴� ���� ������ �����Ͱ� ó���� ��ǻ���� ��ȣ�� �ñ�������. �̸� �������ִ� ���α׷��� �ۼ��϶�.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����. �� ���� �ٺ��� ������ �׽�Ʈ ���̽��� ���� ���� a�� b�� �־�����. (1 �� a < 100, 1 �� b < 1,000,000)
5
1 6
3 7
6 2
7 100
9 635
���
�� �׽�Ʈ ���̽��� ���� ������ �����Ͱ� ó���Ǵ� ��ǻ���� ��ȣ�� ����Ѵ�.
1
7
6
1
9
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
		int tmp = a;
		for (int j = 0; j < b - 1; j++)
			a = tmp * a % 10;
		if (!a) a = 10;
		cout << a << "\n";
	}
}
//int a, b;
//int cal() {
//	int tmp = a % 10;
//	if (!tmp) return 10;
//	else if (b == 1) return a;
//	else if (a == 1 || a == 5 || a == 6) return a;
//	else if (a == 4 || a == 9) {
//		if (b % 2 == 0) return a == 4 ? 6 : 1;
//		else return a;
//	}
//	else {
//		b %= 4;
//		if (b) return (int)pow(a, b) % 10;
//		else return (int)pow(a, 4) % 10;
//	}
//}
//int main() {
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	int t; cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		cout << cal() << "\n";
//	}
//}
