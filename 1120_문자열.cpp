/*
https://www.acmicpc.net/problem/1120
����
���̰� N���� ���� ���ڿ� X�� Y�� ���� ��, �� ���ڿ� X�� Y�� ���̴� X[i] �� Y[i]�� i�� �����̴�. ���� ���, X=��jimin��, Y=��minji���̸�, ���� ���̴� 4�̴�.
�� ���ڿ� A�� B�� �־�����. �̶�, A�� ���̴� B�� ���̺��� �۰ų� ����. ���� A�� ���̰� B�� ���̿� ������ �� ���� ������ ���� ������ �� �� �ִ�.

1.A�� �տ� �ƹ� ���ĺ��̳� �߰��Ѵ�.
2.A�� �ڿ� �ƹ� ���ĺ��̳� �߰��Ѵ�.
�̶�, A�� B�� ���̰� �����鼭, A�� B�� ���̸� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A�� B�� �־�����. A�� B�� ���̴� �ִ� 50�̰�, A�� ���̴� B�� ���̺��� �۰ų� ����, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.
adaabc aababbc

���
A�� B�� ���̰� �����鼭, A�� B�� ���̸� �ּҰ� �ǵ��� ���� ��, �� ���̸� ����Ͻÿ�.
2
�˰��� �з� : �׸��� �˰���, ���Ʈ ����, ���ڿ� ó��, �ùķ��̼�
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXI 51
using namespace std;
char arrA[MAXI], arrB[MAXI];
int res = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> arrA >> arrB;
	int la = strlen(arrA), lb = strlen(arrB);
	if (la == lb) {
		for (int i = 0; i < la; i++)
			if (arrA[i] != arrB[i])
				res++;
	}
	else {
		res = la;
		for (int i = 0; i <= lb - la; i++) {
			int tmp = 0;
			for (int j = 0; j < la; j++)
				if (arrA[j] != arrB[i + j])
					tmp++;
			res = min(res, tmp);
		}
	}
	cout << res << "\n";
}