/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T(1 �� T �� 50)�� �־�����.
�� �׽�Ʈ���̽��� ù ��° �ٿ��� �� ������ N, M�� �־�����.
N, M�� �ڸ����� 1,000,000�� ���� ������, �ڸ����� ���� ����.
3
1011 1100
100101 110100
00110100 10010111
���
�� �׽�Ʈ ���̽����� �� ���� ��Ʈ ���������� ����Ѵ�.
2
1
3
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string n, m;
		cin >> n >> m;
		if (n == m) cout << "0\n";
		else {
			int Ncnt = 0, Mcnt = 0;
			for (int i = 0; n[i] != '\0'; i++) {
				if (n[i] == '0') Ncnt++;
				if (m[i] == '0') Mcnt++;
			}
		}
	}
}