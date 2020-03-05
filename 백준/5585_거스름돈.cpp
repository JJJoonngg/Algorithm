/*
https://www.acmicpc.net/problem/5585
����
Ÿ�δ� ���� JOI��ȭ������ ������ ���. JOI��ȭ������ �ܵ����� 500��, 100��, 50��, 10��, 5��, 1���� ����� �ְ�, 
������ �Ž����� ������ ���� ���� �ܵ��� �ش�. Ÿ�ΰ� JOI��ȭ������ ������ ��� ī���Ϳ��� 
1000�� ���� ���� ���� ��, ���� �ܵ��� ���Ե� �ܵ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���ٷ� �̷�����ְ�, Ÿ�ΰ� ������ ��(1 �̻� 1000�̸��� ����) 1���� �������ִ�.
380
���
������ ��� ������ 1�����θ� �Ǿ� �ִ�. �ܵ��� ���Ե� �ż��� ����Ͻÿ�.
4
*/
#include <iostream>
using namespace std;
int coin[] = { 500,100,50,10,5,1 };
int cnt = 0, pay;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> pay;
	pay = 1000 - pay;
	for (int i = 0; i < 6; i++) {
		if (pay >= coin[i]) {
			int tmp = pay / coin[i];
			pay -= tmp * coin[i];
			cnt += tmp;
		}
	}
	cout << cnt << "\n";
}