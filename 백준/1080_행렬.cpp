/*
https://www.acmicpc.net/problem/1080
����
0�� 1�θ� �̷���� ��� A�� ��� B�� �ִ�. �̶�, ��� A�� ��� B�� �ٲٴµ� �ʿ��� ������ Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� ��ȯ�ϴ� ������ � 3*3ũ���� �κ� ��Ŀ� �ִ� ��� ���Ҹ� ������ ���̴�. (0 -> 1, 1 -> 0)

�Է�
ù° �ٿ� ����� ũ�� N M�� �־�����. N�� M�� 50���� �۰ų� ���� �ڿ����̴�.
��° �ٺ��� N���� �ٿ��� ��� A�� �־�����, �� �����ٺ��� N���� �ٿ��� ��� B�� �־�����.
3 4
0000
0010
0000
1001
1011
1001
���
ù° �ٿ� ������ ������ ����Ѵ�. ���� A�� B�� �ٲ� �� ���ٸ� -1�� ����Ѵ�.
2
*/
#include <iostream>
#define MAXI 51
using namespace std;
int first[MAXI][MAXI];
int second[MAXI][MAXI] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &first[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			scanf("%1d", &second[i][j]);
		}
	}
	int res = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (first[i][j] != second[i][j]) {
				res++;
				for (int a = i; a <= i + 2; a++) {
					for (int b = j; b <= j + 2; b++) {
						first[a][b] = 1 - first[a][b];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (first[i][j] != second[i][j])
				res = -1;
		}
	}
	printf("%d\n", res);
}