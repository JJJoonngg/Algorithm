/*
https://www.acmicpc.net/problem/1100
����
ü������ 8*8ũ���̰�, ���� ĭ�� �Ͼ� ĭ�� �����ư��鼭 ��ĥ�Ǿ� �ִ�. ���� ���� ��ĭ (0,0)�� �Ͼ���̴�.
ü������ ���°� �־����� ��, �Ͼ� ĭ ���� ���� �� �� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٺ��� 8���� �ٿ� ü������ ���°� �־�����. ��.���� �� ĭ�̰�, ��F���� ���� ���� �ִ� ĭ�̴�.
.F.F...F
F...F.F.
...F.F.F
F.F...F.
.F...F..
F...F.F.
.F.F.F.F
..FF..F.
���
ù° �ٿ� ������ ������ ����Ѵ�.
1
*/
#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int cnt = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			char input; cin >> input;
			if(i%2){
				if (j % 2) if (input == 'F') cnt++;
			}
			else {
				if (!(j % 2)) if (input == 'F') cnt++;
			}
		}
	}
	cout << cnt << "\n";
}