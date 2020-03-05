/*
https://www.acmicpc.net/problem/1225
����
A*B�� ����ϴ� ���ܿ��� �����̴� A*B�� ���ο� ������� �����Ϸ��� �Ѵ�.
A���� �� �ڸ��� �̰� * B���� ���Ƿ� �� �ڸ��� �̾� ���Ѵ�.
�� ������ ��� ���� (A�� n�ڸ�, B�� m�ڸ� ����� �� ������ ������ n*m��)�� ���� ���� �����Ϸ��� �Ѵ�.

���� ��� 121*34��
1*3 + 1*4 + 2*3 + 2*4 + 1*3 + 1*4 = 28

�� �ȴ�. �̷��� �������� ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A�� B�� �־�����. �־����� �� ���� ��� 10,000�ڸ��� ���� �ʴ´�.
123 45
121 34
���
ù° �ٿ� �������� ���� ����� ����Ѵ�
54
28
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> a, b;
	long long res = 0;
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.length(); i++) 
		a.push_back(int(tmp[i] - '0'));
	cin >> tmp;
	for (int i = 0; i < tmp.length(); i++)
		b.push_back(int(tmp[i] - '0'));
	for (int i = 0; i < a.size(); i++) 
		for (int j = 0; j < b.size(); j++) 
			res += a[i] * b[j];
	cout << res << "\n";
}