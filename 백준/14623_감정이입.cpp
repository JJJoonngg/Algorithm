/*
�� �������� ��

�Է�
ù ��° �ٿ� ������ B1�� �־�����. �� ��° �ٿ� ������ B2�� �־�����. �Է����� �־����� �� �������� ���̴� 1 �̻� 30 ������ �ڿ����̴�. ���� �� ���������� 1�� �����ϴ� ���� ����ȴ�.
1010
11

1000
100
���
ù ��° �ٿ� �Է����� �־��� �� ������ B1, B2�� ���� �������� ����Ѵ�. ����ϴ� ������ �տ� ���ʿ��� 0�� ������ �� �ʿ� �����ؾ� �Ѵ�. �� ����ϴ� �������� ������ �׻� 1�̾�� �Ѵ�.
11110
100000
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	string b1, b2; cin >> b1 >> b2;
	string res ="";
	long long a1 = 0, a2 = 0;
	int tmp = 1;
	for (int i = b1.length() - 1; i >= 0; i--) {
		a1 += (int)(b1[i] - '0') * tmp;
		tmp *= 2;
	}
	tmp = 1;
	for (int i = b2.length() - 1; i >= 0; i--) {
		a2 += (int)(b2[i] - '0') * tmp;
		tmp *= 2;
	}
	long long ans = a1 * a2;
	while (ans) {
		res += (ans % 2 + '0');
		ans /= 2;
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
}