/*
https://www.acmicpc.net/problem/1051
����
N*Mũ���� ���簢���� �ִ�. �� ĭ�� �� �ڸ� ���ڰ� ���� �ִ�.
�� ���簢������ �������� ���� �ִ� ���� ��� ���� ���� ū ���簢���� ã�� ���α׷��� �ۼ��Ͻÿ�. �̶�, ���簢���� �� �Ǵ� ���� �����ؾ� �Ѵ�.

�Է�
ù° �ٿ� N�� M�� �־�����. N�� M�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� ���� �־�����.
3 5
42101
22100
22101
���
ù° �ٿ� ���� ���簢���� ũ�⸦ ����Ѵ�.
9
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int arr[51][51] = { 0, }, res = 1;
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &arr[i][j]);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			for (int k = 1; k < min(n, m); k++) 
				if (i + k < n && j + k < m && arr[i + k][j] == arr[i][j]
					&& arr[i + k][j + k] == arr[i][j] && arr[i][j + k] == arr[i][j])
					res = max(res, k + 1);
	printf("%d\n", res * res);
}