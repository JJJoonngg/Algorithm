/*
https://www.acmicpc.net/problem/1076
����
���� ��ǰ���� ������ ����. ������ �� 3���� �̿��ؼ� �� ������ �� ������ ��Ÿ����.

ó�� �� 2���� ������ ���̰�, ������ ���� ���ؾ� �ϴ� ���̴�.

������ ���� ���� ǥ�� �̿��ؼ� ���Ѵ�.
��		��	��
black	0	1
brown	1	10
red		2	100
orange	3	1000
yellow	4	10000
green	5	100000
blue	6	1000000
violet	7	10000000
grey	8	100000000
white	9	1000000000
���� ���, ���׿� ���� yellow, violet, red���ٸ� ������ ���� 4,700�� �ȴ�.

�Է�
ù° �ٿ� ù ��° ��, ��° �ٿ� �� ��° ��, ��° �ٿ� �� ��° ���� �־�����. ���� ��� ���� ǥ�� ���� �ִ� ���� �־�����.
yellow
violet
red
���
�Է����� �־��� ������ ���װ��� ����Ͽ� ù° �ٿ� ����Ѵ�.
4700
*/
#include <iostream>
#include <string>
using namespace std;
long long res = 0;
string tmp; int num[3] = { 0, };
string color[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		for (int j = 0; j < 10; j++) {
			if (color[j] == tmp)
				num[i] = j;
		}
	}
	res = num[0] * 10 + num[1];
	for (int i = 0; i < num[2]; i++) res *= 10;
	cout << res << "\n";
}