/*
https://www.acmicpc.net/problem/2675
����
���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. S���� QR Code "alphanumeric" ���ڸ� ����ִ�.

QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.


�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8),
���ڿ� S�� �������� ���еǾ� �־�����. S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.
2
3 ABC
5 /HTP
���
�� �׽�Ʈ ���̽��� ���� P�� ����Ѵ�.
AAABBBCCC
/////HHHHHTTTTTPPPPP
*/
#include <iostream>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; char arr[21];
		scanf("%d", &n); scanf("%s", arr);
		for (int i = 0; arr[i] != '\0'; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i]);
			}
		}
		printf("\n");
	}
}