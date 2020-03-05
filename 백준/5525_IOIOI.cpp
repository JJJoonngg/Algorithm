/*
https://www.acmicpc.net/problem/5525
����
N+1���� I�� N���� O�� �̷���� ������, I�� O�� ����� ������ ���ڿ��� PN�̶�� �Ѵ�.

P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O�� N��)
I�� O�θ� �̷���� ���ڿ� S�� ���� N�� �־����� ��, S�ȿ� PN�� �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. ��° �ٿ��� S�� ���� M�� �־�����, ��° �ٿ� S�� �־�����. (1 �� N �� 1,000,000, 2N+1 �� M �� 1,000,000)
1
13
OOIOIOIOIIOII
���
S�� PN�� �� ���� ���ԵǾ� �ִ��� ����Ѵ�.
4
���ڿ� �˻� kmp�˰��� ����
*/
#include <iostream>
#include <string>
#define MAX 1000001
using namespace std;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, length, cnt = 0;
	string s;
	cin >> n >> length >> s;
	for (int i = 0; i < length; i++) {
		if (s[i + 1] == 'O' && s[i + 2] == 'I') {
			int tmp = 0;
			while (s[i] == 'I' && s[i + 1] == 'O') {
				i += 2; tmp++;
				if (s[i] == 'I' && tmp == n) {
					tmp--; cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
}