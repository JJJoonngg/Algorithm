/*
����
N*Mũ���� �� ��� A�� B�� �־����� ��, �� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� ũ�� N �� M�� �־�����. ��° �ٺ��� N���� �ٿ� ��� A�� ���� M���� ���ʴ�� �־�����. 
�̾ N���� �ٿ� ��� B�� ���� M���� ���ʴ�� �־�����. N�� M�� 100���� �۰ų� ����, ����� ���Ҵ� ������ 100���� �۰ų� ���� �����̴�.
3 3
1 1 1
2 2 2
0 1 0
3 3 3
4 4 4
5 5 100
���
ù° �ٺ��� N���� �ٿ� ��� A�� B�� ���� ����� ����Ѵ�. ����� �� ���Ҵ� �������� �����Ѵ�.
4 4 4
6 6 6
5 6 100
*/
#include <iostream>
#define	MAX 101
using namespace std;
int arr1[MAX][MAX], arr2[MAX][MAX], n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr1[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr2[i][j]);
			arr1[i][j] += arr2[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			printf("%d ", arr1[i][j]);
		printf("\n");
	}
	return 0;
}