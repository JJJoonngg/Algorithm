/*
����
�������� �ü������ ũ�ξ�Ƽ�� ���ĺ��� �Է��� ���� ������. ����, ������ ���� ũ�ξ�Ƽ�� ���ĺ��� ������ ���� �����ؼ� �Է��ߴ�.

���� ���, ljes=njak�� ũ�ξ�Ƽ�� ���ĺ� 6���� �̷���� �ִ�. �ܾ �־����� ��, �� ���� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����Ѵ�.

�Է�
ù° �ٿ� �ִ� 100������ �ܾ �־�����. ���ĺ� �ҹ��ڿ� '-', '='�θ� �̷���� �ִ�.
���� ���� �����ִ� ũ�ξ�Ƽ�� ���ĺ��� �־�����.
ljes=njak
ddz=z=
nljj
c=c=

���
�Է����� �־��� �ܾ �� ���� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����Ѵ�.
6
3
3
2
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	string input;
	string sample[] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	cin >> input;
	for (int i = 0; i < 8; i++) {
		int check = input.find(sample[i]);
		if (check >= 0) {
			input.erase(check, sample[i].length());
			input.insert(check, "!");
			i--;
		}
	}
	cout << input.length() << endl;
	return 0;
}