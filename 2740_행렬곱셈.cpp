/*
����
N*Mũ���� ��� A�� M*Kũ���� ��� B�� �־����� ��, �� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ��� A�� ũ�� N �� M�� �־�����. ��° �ٺ��� N���� �ٿ� ��� A�� ���� M���� ������� �־�����. 
�� ���� �ٿ��� ��� B�� ũ�� M�� K�� �־�����. �̾ M���� �ٿ� ��� B�� ���� K���� ���ʴ�� �־�����.
N�� M, �׸��� K�� 100���� �۰ų� ����, ����� ���Ҵ� ������ 100���� �۰ų� ���� �����̴�.
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3
���
ù° �ٺ��� N���� �ٿ� ��� A�� B�� ���� ����� ����Ѵ�. ����� �� ���Ҵ� �������� �����Ѵ�.
-1 -2 6
-3 -6 12
-5 -10 18
*/
#include <iostream>
#define	MAX 101
using namespace std;
int arr1[MAX][MAX], arr2[MAX][MAX], arr3[MAX][MAX], n, m, k;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr1[i][j]);

	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++) 
			scanf("%d", &arr2[i][j]);

	for (int a = 0; a < n; a++) 
		for (int b = 0; b < k; b++)
			for (int c = 0; c < m; c++) 
				arr3[a][b] += arr1[a][c] * arr2[c][b];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			printf("%d ", arr3[i][j]);
		printf("\n");
	}
	return 0;
}